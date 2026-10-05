//
// Created by Diego Villanueva Fernandez on 04/10/26.
// Matricula: A01199495
//

//POINTERS
//EJEMPLO CLASE

#include <iostream>
#include <string>
using namespace std;
//TEMPLATES
/*
 *template <typename T>
 *permite crear estructuras genericas.
 *
 *T representa un tipo de dato que se decide
 *cuando creamos el objeto.
 */
template<typename T>
struct NodeT {
    T data;
    NodeT<T>* next;

    NodeT(T val) : data(val),next(nullptr){}
};

//CLASE LINKED LIST
/**
 *Una linkedList guarda principalmente:
 *1. head -> pointer al primer Node.
 *2. size -> cantidad de Nodes/
 *
 *El template perimite que la lista guarde
 *cualquier tipo de dato.
 **/
template<typename T>
class LinkedList {
private:
    NodeT<T>* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0){}

    void addFirst(T data) {
        NodeT<T>* nuevo = new NodeT<T>(data);
        nuevo->next = head;
        head = nuevo;
        size++;
    }
    void addLast(T data) {
        NodeT<T>* nuevo = new NodeT<T>(data);
        if (head == nullptr) {
            head = nuevo;
        } else {
            NodeT<T>*aux = head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = nuevo;
        }
        size++;
    }

    ~LinkedList() {
        NodeT<T>* aux = head;
        while (aux != nullptr) {
            NodeT<T> *temp = aux;
            aux = aux->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }

};
//STRUCTS
/**
 *Una struct permite crear un tipo de dato propio
 *que contiene varias variables
 */
struct Persona {
    string nombre;
    int edad;
    Persona* amigo;//ponter a otro struct del mismo tipo;
};

//Node
/**
 *Un Node es una strict que guarda
 *1. Un dato
 *2. un pointer hacia otro Node
 */
struct Node {
    int data;
    Node* next;
};

//Nodo contructor
/*
 *Un constructor es una funcion especial que se ejectua
 *automaticamente cuando se crea un objeto.
 *
 *Sirve para darle valores iniciales al objeto.
 */
struct NodeC {
    int data;
    NodeC* next;
    //CONSTRUCTO NORMAL
    // NodeC(int val) {
    //     data = val;
    //     next = nullptr;
    // }

    //INITIALIZER LIST
    NodeC(int val): data(val),next(nullptr){}
};
//POINTERS
//EJEMPLO CLASE
int x = 42;
int* p = &x;// p apunt a un int
//int* variable significa que es un pointer


/**
 * aqui le estas diciendo a q que reserve unicamente un espacio de memoria
 * para un int y ponle 5
 */
int* q = new int(5);

/**
 * DIFERENCIA ENTRE VARIABLE NORMAL Y POINTER
 * int x = 5;
 * C++ crea y destruye la variable automaticamente.
 *
 * int* x = new int(5);
 * new reserva memoria manualmente y devuelve su direccion.
 * Como usamos new, despues tenemos que liberar esa memoria con delete.
 */

/**
 *DOS POINTERS PUEDEN APUNTAR AL MISMO LUGAR
 *p1 guarda la direccion de y
 *si haciemos que p2 = p1, p2 recibe la misma direccion.
 *Entonces p1 y p2 apuntan a la misma variable.
 */
int y = 10;
int* p1 = &y;
int*p2 = p1;

/**
 * DOS POINTERS A UNA MISMA MEMORIA
 * pA apunta a un int creado con new.
 * pB = pA, entonces ambos apuntan al mismo espacio
 * Si haces un delete pA la memoria se libera pero
 * pB sigue guardando la direccion vieja por lo que se convierte en un dangling pointer
 */
int* pA = new int(10);
int* pB = pA;
int main() {
    *p = 100;

    cout << x << endl; // valor guardado en x
    cout << &x <<endl;// direccion de memoria de x
    cout << p << endl;//direccion de memoria de x
    cout << *p << endl;// va a direcion que tiene guardada y da lo que esta ahi
    cout << q << endl;// imprime la direcion de q
    cout << *q << endl;// imprime el valor guardado en la direccion de q

    delete q; //libera la direccion de memoria que usamos para guardar en int
    /**
     *despues de darle delete, q todavia tiene la direccion de memoria anterior
     *pero esa direccion ya no nos pertenece entonces par aevitar usarla por accidente
     *hacemos:
     */
    q = nullptr;


    cout << q << endl;//nulptr significa que el pointer no apunta a ningun lugar valido

    cout << y << endl;
    cout << p1 << endl;
    cout << p2 <<endl;
    *p2 = 50;
    cout << y << endl;
    cout << *p1 << endl;
    cout << *p2 <<endl;

    cout << *pA <<endl;
    cout << *pB <<endl;
    delete pA;
    pA = nullptr;
    pB = nullptr;// ya no de debe de usar porque liberaste la memoria con delete pA

    Persona persona1;
    persona1.nombre = "Diego";
    persona1.edad = 19;
    persona1.amigo = new Persona{"Maca",19,nullptr};

    cout << persona1.nombre << endl;
    cout << persona1.edad << endl;
    cout << persona1.amigo->nombre << endl;


    //STRUCT + POINTER
    Persona* pp = &persona1;

    cout << pp->nombre << endl;
    cout << pp->edad << endl;

    delete persona1.amigo;
    persona1.amigo = nullptr;

    //Node
    Node n1;
    n1.data = 10;
    n1.next = nullptr;

    Node n2;
    n2.data = 20;
    n2.next = nullptr;

    n1.next = &n2;// para conectar n1 con n2;

    cout << n1.data << endl;//agarra el data de n1
    cout << n1.next->data << endl;// va al siguiende node de n1 y traer la data

    // TRES NODES CONECTADOS
    Node node1;
    node1.data = 10;
    node1.next = nullptr;

    Node node2;
    node2.data = 20;
    node2.next = nullptr;

    Node node3;
    node3.data = 30;
    node3.next = nullptr;

    node1.next = &node2;
    node2.next = &node3;

    cout << node1.data << endl;
    cout << node1.next->data << endl;
    cout << node1.next->next->data << endl;
    //La idea es que cada node solo conoce al siguiente
    // ese encadenamiento hace que DESPUES sea una Linked List

    // El problema es que para empezar a recorrer estos nodos necesitamos saber donde inicia la cadena
    // Para eso existe head, un pointer que nos dice donde esta el primer nodo
    Node* head = &node1;

    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;

    //AUX
    /**
     *aux es un pointer auxiliar.
     *Se usa para recorrer los nodes sin modificar head.
     */

    Node* aux = head;
     cout << aux->data << endl;
     aux = aux->next;
     cout << aux->data << endl;
     aux = aux->next;
     cout << aux->data << endl;
  //   aux = aux->next;
 //   cout << aux->data << endl;// el nullptr;

/**
 *RECORRER NODES CON WHILE
 *mientras aux no sea nullptr,
 *significa que todavia estamos apuntando a un node valido
 *despues de usar el node actual avanzamos al siguiente
 **/
    aux = head;
    while (aux != nullptr) {
        cout << aux->data << endl;
        aux = aux->next;
    }
    // NODE DINAMICO CON NEW
    /**
     * new Node reserva memoria para un Node
     * y devuelve su direccion.
     * Por eso necesitamos un Node*.
     */
    Node* nodo1 = new Node;// reserva memoria para un Node y guarda su direcion en nodo1
    nodo1->data = 50;
    nodo1->next = nullptr;

    cout << nodo1->data << endl;

    Node* nodo2 = new Node;
    nodo2->data = 60;
    nodo2->next = nullptr;

    nodo1->next = nodo2;

    cout << nodo1->data << endl;
    cout << nodo1->next->data << endl;
    delete nodo2;
    delete nodo1;
    nodo1 = nullptr;
    nodo2 = nullptr;

    /**
 * POR QUE LOS NODES SE CREAN CON NEW
 * En una Linked List no sabemos cuantos Nodes se van a necesitar.
 * Se crean dinamicamente conforme se agregan elementos.
 * new permite crear un Node durante la ejecucion del programa
 * y mantenerlo en memoria hasta que decidamos borrarlo con delete.
 */
    Node* head1 = new Node;
    head1->data = 100;
    head1->next = nullptr;

    Node* nuevo = new Node;
    nuevo->data = 110;
    nuevo->next = nullptr;

    head1->next = nuevo;

    Node* nuevo2 = new Node;
    nuevo2->data = 120;
    nuevo2->next = nullptr;

    nuevo->next = nuevo2;

    Node* aux1 = head1;
    while (aux1 != nullptr) {
        cout << aux1->data << endl;
        aux1 = aux1->next;
    }
    //BORRAR TODA UNA LINKED LIST
    /**
     *Para borrar todos los nodes:
     *1. guardamos el node actual en temp.
     *2. avanzamos aux al siguiente node.
     *3. borramos el node que guardamos en temp.
     *
     *Es importante avanzar antes de hacer delete,
     *porque despues de borrar el Node ya no podemos
     *usar su next de forma segura.
     */

    Node* auxBorrar = head1;
    while (auxBorrar != nullptr) {
        Node* temp = auxBorrar;
        auxBorrar = auxBorrar->next;
        delete temp;
    }

    head1 = nullptr;

    NodeC* nodoc = new NodeC(200);
    cout << nodoc->data <<endl;

    delete nodoc;
    nodoc = nullptr;

    //TEMPLATE DE NODO
    NodeT<int>* num = new NodeT<int>(500);
    cout << num->data << endl;

    NodeT<string>* text = new NodeT<string>("Helouu");
    cout << text->data << endl;

    delete num;
    delete text;

    num = nullptr;
    text = nullptr;
    return 0;

}
