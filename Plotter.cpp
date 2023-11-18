//
// Created by pavli on 22/11/2022.
//

#include "Plotter.h"

Plotter::Plotter(Scene *scene) {
    this->scene = scene;
    this->shader = scene->add_shader(std::make_shared<ShaderManager>("../shaders/rand_color.vsh", "../shaders/rand_color.fsh"));
    this->model = make_shared<SphereModel>();
}

void Plotter::update(Subject *subject, Event event) {
    if (event == Event::CLICK_UPDATE) {

        auto data = CallbackController::get_instance()->get_last_data();

        double x = data[0];
        double y = data[1];
        double z = data[2];
        int index = data[3];

        if (scene->can_delete_on_index(index)) {
            return;
        }
        else{
            scene->add_drawable(new Drawable(this->model, true))
                    ->link_shader(this->shader)
                    ->add_transformation(make_shared<Move>(glm::vec3(x, y, z)))
                    ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));
        }
    }
}
