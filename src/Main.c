#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Selector.h"

void Fn_Render(
    unsigned int* c,
    unsigned int* Target,
    int Width,
    int Height,
    float x,float y,
    float w,float h
){
	Rect_RenderXX(Target,Width,Height,x,y,w,h,*c);
}


unsigned int* scolor;
Selector selector;

void Setup(AlxWindow* w){
    scolor = NULL;
    selector = Selector_New(
        (unsigned int[]){
            BLACK,DARK_GRAY,GRAY,LIGHT_GRAY,WHITE,
            DARK_RED,RED,LIGHT_RED,
            DARK_GREEN,GREEN,LIGHT_GREEN,
            DARK_BLUE,BLUE,LIGHT_BLUE,
            DARK_YELLOW,YELLOW,LIGHT_YELLOW,
            DARK_CYAN,CYAN,LIGHT_CYAN,
            DARK_MAGENTA,MAGENTA,LIGHT_MAGENTA,
            DARK_ORANGE,ORANGE,LIGHT_ORANGE,
            DARK_VIOLETTE,VIOLETTE,LIGHT_VIOLETTE,
            DARK_ROSE,ROSE,LIGHT_ROSE,
            DARK_BROWN,BROWN,LIGHT_BROWN,
            GOLD,SILBER
        },
        sizeof(unsigned int),
        37U,
        LIGHT_GRAY,
        0.1f,0.1f,0.8f,0.8f,
        0.25f,0.25f,
        (void(*)(void*,unsigned int*,int,int,float,float,float,float))Fn_Render
    );
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).PRESSED){
        scolor = Selector_Interact(
            &selector,
            GetMouse().x / (float)GetWidth(),
            GetMouse().y / (float)GetHeight()
        );
    }
    if(Stroke(ALX_KEY_UP).PRESSED){
        Selector_Offset(&selector,-1);
    }
    if(Stroke(ALX_KEY_DOWN).PRESSED){
        Selector_Offset(&selector,1);
    }
    if(Stroke(ALX_KEY_TAB).PRESSED){
        Selector_State(&selector,!selector.visible);
    }

    Clear(WHITE);

    Selector_Render(&selector,WINDOW_STD_ARGS);

    if(scolor){
        CStr_RenderAlxFont(WINDOW_STD_ARGS,GetAlxFont(),"Selected",0.0f,0.0f,*scolor);
    }
}
void Delete(AlxWindow* w){
    Selector_Free(&selector);
}

int main(){
    if(Create("Selector",1300,1300,1,1,Setup,Update,Delete))
        Start();
    return 0;
}