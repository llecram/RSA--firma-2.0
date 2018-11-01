#include "rsa.h"
using namespace std;
int main(){
    rsa objeto(conv<ZZ>("1172296651274853512184359565959 "),conv<ZZ>("1113157700406438397457841167119824566353830018031849546323769"));
    cout<<objeto.cifrado("HOLA");
    return 0;
}
