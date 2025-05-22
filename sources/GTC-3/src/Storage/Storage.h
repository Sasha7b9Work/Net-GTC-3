// 2025/05/22 16:18:32 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once
#include "Storage/Measures.h"
#include "Hardware/HAL/HAL.h"


namespace Storage
{
    struct Record
    {
        uint            crc32;      // ���� ������������ ����������� ����� ��� �������� ������������ ������. ���� 0, �� ������ �����
        PackedTime      time;
        float           value;
        uint            type;       // � ���� ����� ������� ��� ��������� � ������������ ��������� ���� � ������� ����� ������� � ���, ��� ������ ����������� ��������� - �� ��������
    };

    void Init();

    // ��������� ��� ���������� � ��������� ������������� ������������ �� ������
    void Append(TypeMeasure::E, float);

    void Update();
}
