import java.util.Scanner;

public class Calculator {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Jakie dzialanie chcesz wykonac?\n1. Dodawanie\n2. Odejmowanie\n3. Mnozenie\n4. Dzielenie\n5. Pierwiastkowanie\n");
        int choice = input.nextInt();
        double a = 0;
        double b = 0;
        double result;
        if (choice != 5){
            System.out.println("Pierwsza liczba:\n");
            a = input.nextDouble();
            System.out.println("Druga liczba:\n");
            b = input.nextDouble();
        } else {
            System.out.println("Liczba do zpierwiastkowania:\n");
            a = input.nextDouble();
        }
        switch(choice){
            case 1:
                System.out.println("Wynik dzialania to: " + (a + b));
                 break;
            case 2:
                System.out.println("Wynik dzialania to: " + (a - b));
                break;
            case 3:
                System.out.println("Wynik dzialania to: " + (a * b));
                break;
            case 4:
                result = a / b;
                System.out.println("Wynik dzialania to: " + result);
                break;
            case 5:
                result = Math.sqrt(a);
                System.out.println("Wynik dzialania to: " + result);
                break;
            default:
                System.out.println("Nieprawidlowa opcja");
                break;

        }
    }
}
