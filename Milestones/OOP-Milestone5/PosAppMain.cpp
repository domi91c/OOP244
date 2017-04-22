#include "PosApp.h"
int main()
{
    ict::PosApp app("posapp.txt", "bill.txt");
    app.testRun();
    return 0;
}