#include <iostream>
#include <string>

char primeravocal (const std::string &str) {
    for(size_t i=1; i< str.length(); ++i){
        char c=str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return c;
    }
    return 'X';
}
std::string calcularRFC (
    const std::string& nombre,
    const std::string& apellidopaterno,
    const std::string& apellidomaterno,
    const std::string& fechanacimiento) {
std::string rfc;

char letrainicial = apellidopaterno[0];
char primeravocalinterna = primeravocal (apellidopaterno);

char inicialam = (!apellidomaterno.empty()) ? apellidomaterno[0] : 'X';

char inicialnombre = nombre[0];


std::string dia = fechanacimiento.substr(0,2);
std::string mes = fechanacimiento.substr(2,2);
std::string anio = fechanacimiento.substr(6,2);
 
 rfc = letrainicial;
 rfc += primeravocalinterna;
 rfc += inicialam;
 rfc += inicialnombre;
 rfc += anio;
 rfc += mes;
 rfc += dia;

 return rfc;
   }
int main(){
   std::string nombre, apellidopaterno, apellidomaterno, fechanacimiento;
   std::cout << "Ingrese su primer nombre: ";
   std::cin >> nombre;
   std::cout << "Ingrese su primer apellido:";
   std::cin >> apellidopaterno;
   std::cout << "Ingrese su segundo apellido: (si no tiene, presione enter.) ";
   std::cin >> apellidomaterno;
   std::cout << "Ingrese su fecha de nacimiento (DDMMAAAA): ";
   std::cin >> fechanacimiento;
   std::string rfc = calcularRFC(nombre, apellidopaterno, apellidomaterno, fechanacimiento);
   std::cout << "Su RFC sin homoclave es: " << rfc << std::endl;

   return 0;
}