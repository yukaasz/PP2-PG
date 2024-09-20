#include "rtweekend.h"

#include "bvh.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "quad.h"
#include "sphere.h"
#include "texture.h"

// Cena principal
void main_scene() {
    // World

    hittable_list world;

    auto checker = make_shared<checker_texture>(2, color(0.6, 0.45, 0.08), color(0.10, 0.05, 0));
    auto material1 = make_shared<metal>(color(0.6, 0.6, 0.6), 0.05);
    auto material2 = make_shared<lambertian>(color(0.06, 0.8, 0.7));
    auto material3 = make_shared<dielectric>(1.5);
    auto material4 = make_shared<lambertian>(color(0.1, 0.1, 0.1));
    auto light_ball = make_shared<diffuse_light>(color(2,2,2));

    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, make_shared<lambertian>(checker)));

    // Quadrado do fundo (caixa do cenário)
    world.add(make_shared<quad>(point3(-11,0, -5), vec3(24, 0, 0), vec3(0, 12, 0), material2));
    world.add(make_shared<quad>(point3(-11,0, -5), vec3(0, 0, 20), vec3(0, 12, 0), material4));
    world.add(make_shared<quad>(point3(13,0, -5), vec3(0, 0, 20), vec3(0, 12, 0), material4));
    world.add(make_shared<quad>(point3(-12,0, -5), vec3(24, 0, 0), vec3(0, 0, 20), make_shared<lambertian>(checker)));
    //world.add(make_shared<quad>(point3(-12,12, -5), vec3(24, 0, 0), vec3(0, 0, 20), material4));

    // Esfera 1 (Metal)
    // Esfera com motion blur
    // auto center1 = point3(-3.00, 2.00, 0);
    // auto center2 = center1 + vec3(0.67, 0.3, 0);
    // world.add(make_shared<sphere>(center1, center2, 1, material1));
    world.add(make_shared<sphere>(point3(-3, 2, 0), 1.0, material1));

    // Esfera 2 (Luz)
    world.add(make_shared<sphere>(point3(-1, 2, 0), 1.0, light_ball));

    // Esfera 3 (Vidro)
    world.add(make_shared<sphere>(point3(1, 2, 0), 1.0, material3));
    world.add(make_shared<sphere>(point3(1, 2, 0), 0.9, material3));

    // Esfera 4 (Luz)
    world.add(make_shared<sphere>(point3(3, 2, 0), 1.0, light_ball));

    // Esfera 5 (Metal)
    world.add(make_shared<sphere>(point3(5, 2, 0), 1.0, material1));

    // Otimização
    world = hittable_list(make_shared<bvh_node>(world));
    
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 800;
    cam.samples_per_pixel = 40;
    cam.max_depth         = 50;
    cam.background        = color(0.08, 0.08, 0.1);

    cam.vfov     = 40;
    cam.lookfrom = point3(1.00, 5.00, 20.00);
    cam.lookat   = point3(1,2,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 20.0;

    cam.render(world);
}

int main() {
    main_scene();
}