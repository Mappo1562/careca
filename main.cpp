#include "EDD.hpp"






void cuatro(tPila &pila){
    //robar 3
    ListaE mano;
    cartas *carta;
    carta= new cartas[3];
    for (int i=0;i<3;i++){
        carta[i].value=i+3;
        cout<<carta[i].value<<"\n";
        mano.append(carta[i]);
    }
    mano.erase();

}

void iniciar(){
    tLista mazosr;
    tPila pila;
    cartas carta;
    int pos,a;
    //  creacion de cada valor de las cartas

    for (int i=0;i<104;i++){
        carta.estado=DESCONOCIDA;
        carta.value=(i%13)+2;
        mazosr.append(carta);
    }
    for (int i=104;i<=108;i++){
        carta.estado=DESCONOCIDA;
        carta.value=JOKER;
        mazosr.append(carta);
    }
    mazosr.print();
/*
    for (int i=0;i<108;i++)
        cout<<mazosr[i].value<<"\n";
*/

    srand(time(0));
    carta.value=0;
    for (int i=0;i<108;i++){
        pos=1+(rand()%108);
        mazosr.moveToPos(pos);
        if (mazosr.getValue().value){
            pila.push(mazosr.getValue());
            mazosr.insert(carta);
        }
        else{
            while(mazosr.getValue().value==0){
                pos=(pos*pos*3+pos*7+1)%108;
                mazosr.moveToPos(pos);
            }
            pila.push(mazosr.getValue());
            mazosr.insert(carta);
        }
    }
    do{
        cout<<"ingrese la cantidad de jugadores (min 2 max 6): ";
        cin>>a;
        switch (a){
            case 2:
                /* code */
                break;
            case 3:
                break;
            case 4:
                cout<<"escogiste el 4\n";
                cuatro(pila);
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                cout<<"escoge una opcion valida perkin\n";
                break;
        }
    }while(a>6||a<2);
}



int main(){
    iniciar();
    return 0;
}