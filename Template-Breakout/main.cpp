#include <iostream>

#include "Services/GameManager.h"

#if defined(_DEBUG) && defined(_CONSOLE)
int main()
#else
int WinMain()
#endif // _DEBUG
{
    return I(GameManager)->Run();
}
