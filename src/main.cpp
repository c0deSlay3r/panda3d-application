#include <pandaFramework.h>
#include <pandaSystem.h>

int main(int argc, char* argv[])
{
    PandaFramework fr;
    fr.open_framework(argc, argv);

    fr.set_window_title("Hello ;)");
    WindowFramework *window = fr.open_window();


    fr.main_loop();
    fr.close_framework();

    return 0;
}