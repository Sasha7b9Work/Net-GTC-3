// 2025/05/22 16:18:32 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Storage/Measures.h"


namespace Storage
{
    void Init();

    // ��������� ��� ���������� � ��������� ������������� ������������ �� ������
    void Append(TypeMeasure::E, float);

    void Update();
}
