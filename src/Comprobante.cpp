#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>
#include <iomanip>

#include "Comprobante.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "Funciones.h"
#include "rlutil.h"
#include "Fecha.h"
#include "Reportes.h"

using namespace std;
using namespace rlutil;



Comprobante::Comprobante()
{

}

void Comprobante::setIdComp(int idComp)
{
    _idComp=idComp;
}
void Comprobante::setLetra(char* letra)
{
    strcpy(_letra,letra);
}

void Comprobante::setFechaContabilizacion(Fecha contabilizacion)
{
    _fechaContabilizacion=contabilizacion;
}

void Comprobante::setFechaFactura(Fecha factura)
{
    _fechaComp=factura;
}

void Comprobante::setTipo(int tipo)
{
   _tipo=tipo;
}

void Comprobante::setPv(int pv)
{

    if(pv<9999)
    {
        _pv=pv;
    }

}
void Comprobante::setNumFac(int numFac)
{
   if(numFac<99999999)
    {
        _numFac=numFac;
    }

}
void Comprobante::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void Comprobante::setCantidad(int cant)
{
    _cantidad=cant;
}
void Comprobante::setPU(float pu)
{
    _PU=pu;
}
void Comprobante::setIVA(float iva)
{
    _IVA=iva;
}
void Comprobante::setImporteTotal(float importe)
{
    _importeTotal=importe;
}
void Comprobante::setEstado(int estado)
{
    _estado=estado;
}
int Comprobante::getIdComp()
{
    return _idComp;
}
char * Comprobante::getLetra()
{
    return _letra;
}

Fecha Comprobante::getFechaContabilizacion()
{
    return _fechaContabilizacion;
}

Fecha Comprobante::getFechaFactura()
{
    return _fechaComp;
}
int Comprobante::getTipo()
{
    return _tipo;
}

int Comprobante::getIdProveedor()
{
    return _idProveedor;
}
int Comprobante::getPV()
{
    return _pv;
}
int Comprobante::getNumFac()
{
    return _numFac;
}
int Comprobante::getCuentaContable()
{
    return _cuentaContable;
}
int Comprobante::getCantidad()
{
    return _cantidad;
}
float Comprobante::getPU()
{
    return _PU;
}
float Comprobante::getIVA()
{
    return _IVA;
}

float Comprobante::getImporteTotal()
{
    return _importeTotal;
}
int  Comprobante::getEstado()
{
    return _estado;
}
void Comprobante::cargar(int tipo)
{
    marco_comprobante(1,2,80,48);

    setlocale(LC_ALL, "Spanish");
    int x;
    setTipo(tipo);

    if(getTipo()==1){
        gotoxy(4,3);cout<<"ESTA CARGANDO UNA FACTURA" <<endl;
    }
    if(getTipo()==2){
        gotoxy(4,3);cout<<"ESTA CARGANDO UNA NOTA DE CREDITO"<<endl;
    }

    gotoxy(4,5);cout<<"FECHA CONTABILIZACI�N"<<endl;

    int d,m,a;
    gotoxy(4,6);cout<<"DIA: "<<endl;
    gotoxy(9,6);cin>>d;
    while (d <= 0 || d >32)
    {
        gotoxy(5,7);cout << "Ingrese un dia entre 1 y 31" << endl;
        gotoxy(5,8);cout << "DIA: " << endl;
        gotoxy(10,8);cin >> d;
    }

    gotoxy(4,9);cout<<"MES: "<<endl;
    gotoxy(9,9);cin>>m;
    while (m <=0 || m >13)
    {
       gotoxy(5,10);cout << "Ingrese un mes entre 1 Y 12" << endl;
       gotoxy(5,11);cout << "MES: " << endl;
       gotoxy(9,11);cin >> m;
    }

    gotoxy(4,12);cout<<"A�O: "<<endl;
    gotoxy(9,12);cin>>a;

    while (a<1990)
    {
        gotoxy(5,13);cout << "iNGRESE UN A�O MAYOR A 1990" << endl;
        gotoxy(5,14);cout << "A�O: " << endl;
        gotoxy(9,14);cin >> a;
    }


    _fechaContabilizacion.setDia(d);
    _fechaContabilizacion.setMes(m);
    _fechaContabilizacion.setAnio(a);

    gotoxy(4,15);cout<<"FECHA COMPROBANTE"<<endl;

    int dd,mm,aa;
    gotoxy(4,16);cout<<"DIA: "<<endl;
    gotoxy(9,16);cin>>dd;
    while (dd <= 0 || dd >32)
    {
        gotoxy(4,17);cout << "Ingrese un dia entre 1 Y 31" << endl;
        gotoxy(4,18);cout << "DIA: " << endl;
        gotoxy(9,18);cin >> dd;
    }

    gotoxy(4,19);cout<<"MES: "<<endl;
    gotoxy(9,19);cin>>mm;
    while (mm <=0 || mm >13)
    {
        gotoxy(4,20);cout << "Ingrese el mes de  1 Y 12" << endl;
        gotoxy(4,21);cout << "MES: "<< endl;
        gotoxy(9,21);cin >> mm;
    }

    gotoxy(4,22);cout<<"A�O: "<<endl;
    gotoxy(9,22);cin>>aa;

    while (aa<1990)
    {
        gotoxy(4,23);cout << "Ingrese un a�o mayor a 1990" << endl;
        gotoxy(4,24);cout << "A�O: "<< endl;
        gotoxy(9,24);cin >> aa;
    }

    _fechaComp.setDia(dd);
    _fechaComp.setMes(mm);
    _fechaComp.setAnio(aa);

    gotoxy(4,25);cout<<"PROVEEDOR"<<endl;

    gotoxy(4,26);rand_proveedores();

    // llamar a la funcion randomProveedor() --> Mostrar un random de 5 proveedores con su categoria
    gotoxy(4,32);cout<<"ELIGE UN PROVEEDOR"<<endl;
    gotoxy(4,33);cin>> _idProveedor;

    gotoxy(4,35);buscarNombProveedor(_idProveedor);

    gotoxy(4,36);cout<<"LETRA: "<<endl;
    gotoxy(11,36);cin>> _letra;
    // Mostrar opciones
    gotoxy(13,36);cout<<"PV: "<<endl;
    gotoxy(17,36);cin>> _pv;
    gotoxy(19,36);cout<<"NUMERO: "<<endl;
    gotoxy(27,36);cin>> _numFac;
    //cuenta contable del proveedor
    gotoxy(4,37);cout<<"CUENTA CONTABLE"<<endl;
    //gotoxy(4,38);
    gotoxy(4,39);cout<<"CANTIDAD: "<<endl;
    gotoxy(14,39);cin >> _cantidad;
    gotoxy(20,39);cout<<"PRECIO: $ "<<endl;
    gotoxy(30,39);cin >> _PU;
    float tasa;
    tasa=buscarAlicuota(_idProveedor);
    float IVA;

    IVA=(((_PU*_cantidad)*tasa)/100);
    setIVA(IVA);
    cout << fixed;
    gotoxy(37,39);cout<<"IVA: $  "<< setprecision(2) <<getIVA()<<endl;

    _importeTotal=(_PU*_cantidad)+IVA;
    cout << fixed;
    gotoxy(60,39);cout<<"TOTAL: $ "<< setprecision(2) <<_importeTotal<< endl;

    setEstado(1);
    resetColor();
}

void Comprobante::mostrar()
{

    char nom[45]={};
    strcpy(nom,buscarNombProv2(_idProveedor));
    cout << left;
    _fechaContabilizacion.mostrar();
    _fechaComp.mostrar();
    cout<< setw(18) <<  _idProveedor;
    cout<< setw(30) << nom;
    cout<< setw(6) << _tipo;
    cout<< setw(13) << _numFac;
    cout<< setw(16) << _cuentaContable;
    cout<< setw(14) <<"IMPORTE NETO";
    cout<< setw(10) << getIVA();
    cout<< setw(10) << _importeTotal;
    cout << endl;

}

void Comprobante::listarComprobantes()
{
    int i=0;
    cout << left;
    cout<< "--------------------------------------" << endl;
    cout<< "        LISTADO COMPROBANTES          " << endl;
    cout<< "--------------------------------------" << endl;

    cout<< setw(23) <<" FECHA CONTABILIZACION ";
    cout<< setw(23) <<" FECHA COMPROBANTE ";
    cout<< setw(18) <<" CODIGO PROVEEDOR ";
    cout<< setw(30) <<" NOMBRE PROVEEDOR ";
    cout<< setw(6) << " TIPO ";
    cout<< setw(13) << " COMPROBANTE ";
    cout<< setw(16) <<" CUENTA CONTABLE ";
    cout<< setw(14) <<" IMPORTE NETO ";
    cout<< setw(10) <<" TASA IVA ";
    cout<< setw(10) <<" TOTAL ";
    cout << endl;

    while(leerDeDisco(i))
    {
        mostrar();
        i++;
    }
    cout << endl;
}

bool Comprobante::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return guardo;
}
bool Comprobante::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("comprobantes.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    lectura = fread(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return lectura;
}

void Comprobante::guardarEnDisco(int pos)
{

    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return;
}

