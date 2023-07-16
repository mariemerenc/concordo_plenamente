#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "sistema.h"
#include "exec.h"

int main(){
    Sistema sistema;
    Executor executor(&sistema);
    executor.executar();
    return 0;
}