#include <iostream>
using namespace std;

void imprimirEntrega(int operarios[6], int error, string alfajores, int cantidad, int fueraProduccionOp[6], int ch[6], int dl[6], int fr[6], int cajasC, int cajasD, int cajasF) {
    // imprimimos los operarios con su cantidad de alfajores producidos segun su tipo y con su cantidad de fuera de produccion
    for (int i = 0; i < 6; i++) {
        cout << "Operario: " << i+1 << endl;
        cout << "\tAlfajores chocolate: " << ch[i] << endl;
        cout << "\tAlfajores dulce de leche: " << dl[i] << endl;
        cout << "\tAlfajores fruta: " << fr[i] << endl;
        cout << "\tAlfajores fuera de produccion: " << fueraProduccionOp[i] << endl;
    }

    cout << "Ganancias por cajas de alfajores de chocolate: " << cajasC * 1200 << endl; 
    cout << "Ganancias por cajas de alfajores de dulce de leche: " << cajasD * 1000 << endl;
    cout << "Ganancias por cajas de alfajores de fruta: " << cajasF * 1500 << endl;

    // imprimimos la cantidad de entregas totales
    cout << "Entregas con error: " << error << endl;
}

int main(void) {
    // inicializamos las variables a usar
    int operarios[6] = {1,2,3,4,5,6}; // los operarios
    int error = 0, cajasC = 0, cajasD = 0, cajasF = 0; // contador de errores y contador de cajas distinguiendo por tipo
    int ch[6] = {0}; // contador de alfajores de chocolate segun el operario
    int dl[6] = {0}; // contador de alfajores de dulce de leche segun el operario
    int fr[6] = {0}; // contador de alfajores de fruta segun el operario
    int fueraProduccionOp[6] = {0}; // contador de alfajores fuera de produccion segun el operario

    // Aclaracion importante, al estar los operarios del 1 al 6 se me permite almacenar los contadores en arrays a parte
    // ya que al estar ordenados comparten posición.

    while (1) {
        // variables temporales, se reinician en cada vuelta
        int i = 0; // indice de los operarios 
        string alfajores; // tipo de alfajor
        int cantidad = 0; // cantidad producida

        // le solicito al usuario los datos
        cout << "Que operario realizo la elaboracion de los alfajores? (Del 1 al 6 inclusive)" << endl;
        cin >> i;

        cout << "Que tipo de alfajores elaboro? (Chocolate(c), Dulce de leche(d), Fruta(f))" << endl;
        cin >> alfajores;

        cout << "Cuantos alfajores hizo?" << endl;
        cin >> cantidad;

        // sumo la cantidad de alfajores en base a su tipo y armo las cajas segun su tipo
        if      (alfajores == "C" || alfajores == "c") { ch[i-1] += cantidad; cajasC += cantidad / 6; }
        else if (alfajores == "D" || alfajores == "d") { dl[i-1] += cantidad; cajasD += cantidad / 6; }
        else if (alfajores == "F" || alfajores == "f") { fr[i-1] += cantidad; cajasF += cantidad / 6; } 

        // reviso si quedan fuera de produccion
        
        if (cantidad % 6 != 0) {
            // en caso de haber se suma al error y la cantidad de alfajores fuera de produccion
            fueraProduccionOp[i-1] += cantidad % 6;
            error++;
        }

        // se le pregunta al usuario si desea seguir ingresando entregas
        string choice;
        cout << "Desea seguir ingresando producciones? s/n" << endl;
        cin >> choice;

        if (choice == "n" || choice == "N") {
            // en caso de no se llama a imprimir y se sale del while (perdon por tantos argumentos)
            imprimirEntrega(operarios,error,alfajores,cantidad,fueraProduccionOp,ch,dl,fr,cajasC,cajasD,cajasF);
            break;
        }
    }
    return 0;
}