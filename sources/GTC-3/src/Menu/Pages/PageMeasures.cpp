// 2023/06/01 09:44:24 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Menu/Pages/Pages.h"
#include "Settings/Settings.h"
#include "Storage/Measures.h"


#define DEF_GOVERNOR_MIN(_name, page_self, _min, _max, type)                                        \
DEF_GOVERNOR(_name, "������ ���", *page_self, nullptr, _min, _max, gset.measures.limit_min[type])

#define DEF_GOVERNOR_MAX(_name, page_self, _min, _max, type)                                        \
DEF_GOVERNOR(_name, "������ ����", *page_self, nullptr, _min, _max, gset.measures.limit_max[type])

#define DEF_STATE_MIN(_name, page_self, type)                                                       \
DEF_STATE(_name, "�������� ���", *page_self, nullptr, nullptr, type, true)

#define DEF_STATE_MAX(_name, page_self, type)                                                       \
DEF_STATE(_name, "�������� ����", *page_self, nullptr, nullptr, type, false)

#define DEF_STATE_MIN_MAX(_name, page_self, type)                                                   \
DEF_STATE_MIN(_name##ValueMin, page_self, type)                                                     \
DEF_STATE_MAX(_name##ValueMax, page_self, type)


extern const DPage pageMain;


//-------------------------------------------------------------------------------------
void ClosePageTemperature(bool)
{
    PageMeasures::Temperature::self->Close();
}

DEF_BUTTON(bClosePageTemperature,
    "�������",
    *PageMeasures::Temperature::self,
    ClosePageTemperature,
    nullptr,
    nullptr
)

DEF_CHOICE_2(chTemperature,
    "����������",
    *PageMeasures::Temperature::self,
    nullptr,
    nullptr,
    gset.display.show_measure[TypeMeasure::Temperature],
    "���", "��"
)


DEF_GOVERNOR_MIN(gTemperatureLimitMin, PageMeasures::Temperature::self, -30, 60, TypeMeasure::Temperature);

DEF_GOVERNOR_MAX(gTemperatureLimitMax, PageMeasures::Temperature::self, -30, 60, TypeMeasure::Temperature);

DEF_STATE_MIN_MAX(sTemperature, PageMeasures::Temperature::self, TypeMeasure::Temperature);


void OnPress_ResetTemperature(bool)
{
    gset.ResetMeasure(TypeMeasure::Temperature);
}


DEF_BUTTON(bResetTemperature,
    "����� ���-����",
    *PageMeasures::Temperature::self,
    OnPress_ResetTemperature,
    nullptr,
    nullptr
)


DEF_PAGE_7(pageTemperature, //-V1027
    "�����������",
    *PageMeasures::self,
    nullptr,
    nullptr,
    chTemperature,
    gTemperatureLimitMin,
    gTemperatureLimitMax,
    sTemperatureValueMin,
    sTemperatureValueMax,
    bResetTemperature,
    bClosePageTemperature
)


//------------------------------------------------------------------------------------
void ClosePagePressure(bool)
{
    PageMeasures::Pressure::self->Close();
}

DEF_BUTTON(bClosePagePressure,
    "�������",
    *PageMeasures::Pressure::self,
    ClosePagePressure,
    nullptr,
    nullptr
)

DEF_CHOICE_2(chPressure,
    "����������",
    *PageMeasures::Pressure::self,
    nullptr,
    nullptr,
    gset.display.show_measure[TypeMeasure::Pressure],
    "���", "��"
)

DEF_GOVERNOR_MIN(gPressureMin, PageMeasures::Pressure::self, 225, 1000, TypeMeasure::Pressure);

DEF_GOVERNOR_MAX(gPressureMax, PageMeasures::Pressure::self, 225, 1000, TypeMeasure::Pressure);

DEF_STATE_MIN_MAX(sPressure, PageMeasures::Pressure::self, TypeMeasure::Pressure);


void OnPress_ResetPressure(bool)
{
    gset.ResetMeasure(TypeMeasure::Pressure);
}


DEF_BUTTON(bResetPressure,
    "����� ���-����",
    *PageMeasures::Pressure::self,
    OnPress_ResetPressure,
    nullptr,
    nullptr
)


DEF_PAGE_7(pagePressure, //-V1027
    "��������",
    *PageMeasures::self,
    nullptr,
    nullptr,
    chPressure,
    gPressureMin,
    gPressureMax,
    sPressureValueMin,
    sPressureValueMax,
    bResetPressure,
    bClosePagePressure
)


//-------------------------------------------------------------------------------------
void ClosePageHumidity(bool)
{
    PageMeasures::Humidity::self->Close();
}

DEF_BUTTON(bClosePageHumidity,
    "�������",
    *PageMeasures::Humidity::self,
    ClosePageHumidity,
    nullptr,
    nullptr
)

DEF_CHOICE_2(chHumidity,
    "����������",
    *PageMeasures::Humidity::self,
    nullptr,
    nullptr,
    gset.display.show_measure[TypeMeasure::Humidity],
    "���", "��"
)

DEF_GOVERNOR_MIN(gHumidityMin, PageMeasures::Humidity::self, 10, 98, TypeMeasure::Humidity);

DEF_GOVERNOR_MAX(gHumidityMax, PageMeasures::Humidity::self, 10, 98, TypeMeasure::Humidity);

DEF_STATE_MIN_MAX(sHumidity, PageMeasures::Humidity::self, TypeMeasure::Humidity);

void OnPress_ResetHumidity(bool)
{
    gset.ResetMeasure(TypeMeasure::Humidity);
}


DEF_BUTTON(bResetHumidity,
    "����� ���-����",
    *PageMeasures::Humidity::self,
    OnPress_ResetHumidity,
    nullptr,
    nullptr
)

DEF_PAGE_7(pageHumidity, //-V1027
    "���������",
    *PageMeasures::self,
    nullptr,
    nullptr,
    chHumidity,
    gHumidityMin,
    gHumidityMax,
    sHumidityValueMin,
    sHumidityValueMax,
    bResetHumidity,
    bClosePageHumidity
)


//------------------------------------------------------------------------------------
void ClosePageDewPoint(bool)
{
    PageMeasures::DewPoint::self->Close();
}

DEF_BUTTON(bClosePageDewPoint,
    "�������",
    *PageMeasures::DewPoint::self,
    ClosePageDewPoint,
    nullptr,
    nullptr
)

DEF_CHOICE_2(chDewPoint,
    "����������",
    *PageMeasures::DewPoint::self,
    nullptr,
    nullptr,
    gset.display.show_measure[TypeMeasure::DewPoint],
    "���", "��"
)

DEF_GOVERNOR_MIN(gDewPointMin, PageMeasures::DewPoint::self, -100, 100, TypeMeasure::DewPoint);

DEF_GOVERNOR_MAX(gDewPointMax, PageMeasures::DewPoint::self, -100, 100, TypeMeasure::DewPoint);

DEF_STATE_MIN_MAX(sDewPoint, PageMeasures::DewPoint::self, TypeMeasure::DewPoint);

void OnPress_ResetDewPoint(bool)
{
    gset.ResetMeasure(TypeMeasure::DewPoint);
}


DEF_PAGE_7(pageDewPoint, //-V1027
    "����� ����",
    *PageMeasures::self,
    nullptr,
    nullptr,
    chDewPoint,
    gDewPointMin,
    gDewPointMax,
    sDewPointValueMin,
    sDewPointValueMax,
    bResetHumidity,
    bClosePageDewPoint
)


static bool fixed_marked = false;

static void FixateMeasures(bool)
{
    Measures::SetFixed(!Measures::IsFixed());

    fixed_marked = Measures::IsFixed();
}

DEF_BUTTON(bFixateMeasures,
    "��������",
    *PageMeasures::self,
    FixateMeasures,
    nullptr,
    &fixed_marked
)


static void CloseMeasures(bool)
{
    PageMeasures::self->Close();
};

DEF_BUTTON(bCloseMeasures,
    "�������",
    *PageMeasures::self,
    CloseMeasures,
    nullptr,
    nullptr
)

DEF_PAGE_6(pageMeasures, //-V1027
    "���������",
    pageMain,
    nullptr,
    nullptr,
    bFixateMeasures,
    pageTemperature,
    pagePressure,
    pageHumidity,
    pageDewPoint,
    bCloseMeasures
)

const Page *const PageMeasures::self = (const Page *)&pageMeasures;
const Page *const PageMeasures::Temperature::self = (const Page *)&pageTemperature;
const Page *const PageMeasures::Pressure::self = (const Page *)&pagePressure;
const Page *const PageMeasures::Humidity::self = (const Page *)&pageHumidity;
const Page *const PageMeasures::DewPoint::self = (const Page *)&pageDewPoint;
