#include <iostream>
//La clase CArithmetic encapsula operaciones aritméticas
class CArithmetic
{
public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
};

double CArithmetic::Addition(double a, double b)
{
    return a + b;
}

double CArithmetic::Substraction(double a, double b)
{
    return a - b;
}

double CArithmetic::Multiplication(double a, double b)
{
    return a * b;
}

double CArithmetic::Division(double a, double b)
{
    if (b != 0)
        return a / b;
    else
    {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
        return 0;
    }
}
//Los métodos de la clase son todos estáticos
//Los métodos estáticos implementan operaciones aritméticas básicas: Addition, Substraction, Multiplication y Division.
//Cada método toma dos parámetros de tipo double que representan los números en los que se realizará la operación.
int main()
{
    double num1, num2;
    char operation;
    //Dentro del bucle, se solicita al usuario que ingrese una operación y dos números.
    while (true)
    {
        std::cout << "Ingrese una operacion (+, -, *, /) o 'q' para salir: ";
        std::cin >> operation;

        if (operation == 'q')
            break;

        std::cout << "Ingrese 2 numeros: ";
        std::cin >> num1 >> num2;
        //el switch determina qué operación se seleccionó y llama al método correspondiente de la clase CArithmetic.
        double result;
        switch (operation)
        {
            case '+':
                result = CArithmetic::Addition(num1, num2);
                std::cout << "Resultado: " << result << std::endl;
                break;
            case '-':
                result = CArithmetic::Substraction(num1, num2);
                std::cout << "Resultado: " << result << std::endl;
                break;
            case '*':
                result = CArithmetic::Multiplication(num1, num2);
                std::cout << "Resultado: " << result << std::endl;
                break;
            case '/':
                result = CArithmetic::Division(num1, num2);
                std::cout << "Resultado: " << result << std::endl;
                break;
            default:
                std::cout << "Operacion Invalida." << std::endl;
                break;
        }
    }

    return 0;
}
