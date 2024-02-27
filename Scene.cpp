//
// Created by pavli on 23/10/2022.
//

#include "Scene.h"
#include "data/axes.h"

std::shared_ptr<ShaderManager> Scene::add_shader(std::shared_ptr<ShaderManager> shader) {
    shaders.push_back(shader);
    return shader;
}

Drawable* Scene::add_drawable(Drawable* drawable) {
    drawables.push_back(drawable);
    return drawable;
}

void Scene::link_lights() {

    auto point_light = (new PointLight(0, 1, 0))->set_color(2, 0.647, 1.812);
    auto dir_light = (new DirLight(0, 1, 0))->set_color(0.0, 0.31, 0.1);
    auto spot_light = (new SpotLight(glm::vec3(0, 3, 0), glm::vec3(0, -1, 0)))->set_color(1, 1, 1);

    for (auto &shader: shaders) {
        shader->use_shaders();

        shader->set_uniform("lights[0]", point_light);
        shader->set_uniform("lights[1]", dir_light);
        shader->set_uniform("lights[3]", spot_light);
    }

    lights.push_back(point_light);
    lights.push_back(dir_light);
    lights.push_back(spot_light);
}

void Scene::link_shaders(Camera *camera, Window *window) {
    auto proj = window->get_projection();
    auto view = camera->get_view();

    auto spot_light = (new SpotLight(camera->get_position(), camera->get_direction()))->set_color(0.885, 0.647, 0.112);
    lights.push_back(spot_light);

    for (auto &shader: shaders) {
        camera->registerObserver(shader.get());
        window->registerObserver(shader.get());

        shader->use_shaders();

        shader->set_uniform("projection", proj);
        shader->set_uniform("view", view);

        shader->set_uniform("spotlight", spot_light);

        shader->set_uniform("texture_0", 0);
        shader->set_uniform("texture_1", 1);
    }
}

void Scene::add_cubemap(std::string folder) {
    cubemap = new CubeMap(folder);
    add_shader(cubemap->get_shader());
}

void Scene::draw() {

    if (cubemap) {
        glStencilFunc(GL_ALWAYS, 0, 0xFF);

        glDepthFunc(GL_LEQUAL);
        cubemap->render();
        glDepthFunc(GL_LESS);
    }

    int i = 1;
    for (auto &drawable: drawables) {
        glStencilFunc(GL_ALWAYS, i, 0xFF);
        drawable->render();
        i++;
    }
}


void Scene::create_axes(std::shared_ptr<ShaderManager> shader) {
    auto ax_model = make_shared<DataModel>(4, sizeof(ax), ax, 3, 3);

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader);

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader)
            ->add_transformation(make_shared<Rotate>(90, glm::vec3(0.0, 0.0, 0.1)));

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader)
            ->add_transformation(make_shared<Rotate>(-90, glm::vec3(0.0, 1.0, 0.0)));
}

bool Scene::can_delete_on_index(int i) {
    i = i - 1;
    if (i < 0) return false;
    if (i >= drawables.size()) return false;

    if (drawables[i]->was_plotted()) {
        drawables.erase(drawables.begin() + i);
        return true;
    };
    return false;
}

