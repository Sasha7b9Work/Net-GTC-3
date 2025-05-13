// (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Device.h"
#include <cstdio>

/*
*   ������ ������� �������� ���������� ID, ������� �������� ����� �������� ����� ����
*/


#ifndef WIN32
    #if __ARMCC_VERSION != 6230001
        // �� ������ ������� ������������ �� �����������
        #error "Requires ARM Compiler V6.23 from uVision 5.42a"
    #endif
#endif


int main(void)
{
    Device::Init();
    
    while (true)
    {
        Device::Update();
    }
}
