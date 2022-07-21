#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};
float *EspAlive = CREATE_COLOR(255, 255, 255, 255);
Vector3 add(Vector3 a, Vector3 b) {
    Vector3 c;
    c.x= a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}
void Draw3dBox(ImDrawList *draw,Vector3 Transform,void * camera,int glHeight,int glWidth)
{
    Vector3 position2 = add(Transform, Vector3(0.6, 1.6, 0.6)); 
    Vector3 position3 = add(Transform, Vector3(0.6, 0, 0.6));
    Vector3 position4 = add(Transform, Vector3(-0.5, 0, 0.6)); 
    Vector3 position5 = add(Transform, Vector3(-0.5, 1.6, 0.6));
    Vector3 position6 = add(add(Transform, Vector3(0.6, 1.6, 0)), Vector3(0, 0, -0.6));
    Vector3 position7 = add(add(Transform, Vector3(0.6, 0, 0)), Vector3(0, 0, -0.6));
    Vector3 position8 = add(add(Transform, Vector3(-0.5, 0, 0)), Vector3(0, 0, -0.6)); 
    Vector3 position9 = add(add(Transform, Vector3(-0.5, 1.6, 0)), Vector3(0, 0, -0.6));

    Vector3 vector = WorldToScreenPoint(camera, position2);
    Vector3 vector2 = WorldToScreenPoint(camera, position3);
    Vector3 vector3 = WorldToScreenPoint(camera, position4);
    Vector3 vector4 = WorldToScreenPoint(camera, position5);
    Vector3 vector5 = WorldToScreenPoint(camera, position6);
    Vector3 vector6 = WorldToScreenPoint(camera, position7);
    Vector3 vector7 = WorldToScreenPoint(camera, position8);
    Vector3 vector8 = WorldToScreenPoint(camera, position9);

    if (vector.z > 0 && vector2.z > 0 && vector3.z > 0 && vector4.z > 0 && vector5.z > 0 && vector6.z > 0 && vector7.z > 0 && vector8.z > 0 )
    {
        draw->AddLine({(float) (glWidth -(glWidth -vector.x)),(glHeight -vector.y)}, {glWidth - (glWidth - vector2.x),glHeight -vector2.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector3.x)),(glHeight -vector3.y)}, {glWidth - (glWidth - vector2.x),glHeight -vector2.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector.x)),(glHeight -vector.y)}, {glWidth - (glWidth - vector4.x),glHeight -vector4.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector4.x)),(glHeight -vector4.y)}, {glWidth - (glWidth - vector3.x),glHeight -vector3.y}, ToColor(EspAlive), 2.0f);

        draw->AddLine({(float) (glWidth -(glWidth -vector5.x)),(glHeight -vector5.y)}, {glWidth - (glWidth - vector6.x),glHeight -vector6.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector7.x)),(glHeight -vector7.y)}, {glWidth - (glWidth - vector6.x),glHeight -vector6.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector5.x)),(glHeight -vector5.y)}, {glWidth - (glWidth - vector8.x),glHeight -vector8.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector8.x)),(glHeight -vector8.y)}, {glWidth - (glWidth - vector7.x),glHeight -vector7.y}, ToColor(EspAlive), 2.0f);

        draw->AddLine({(float) (glWidth -(glWidth -vector.x)),(glHeight -vector.y)}, {glWidth - (glWidth - vector5.x),glHeight -vector5.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector2.x)),(glHeight -vector2.y)}, {glWidth - (glWidth - vector6.x),glHeight -vector6.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector3.x)),(glHeight -vector3.y)}, {glWidth - (glWidth - vector7.x),glHeight -vector7.y}, ToColor(EspAlive), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector4.x)),(glHeight -vector4.y)}, {glWidth - (glWidth - vector8.x),glHeight -vector8.y}, ToColor(EspAlive), 2.0f);
    
    }
}
