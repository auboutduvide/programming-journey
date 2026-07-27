import java.util.Random;
import java.util.Scanner;

public class GuessTheNumber {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random random = new Random();

        System.out.println("Zgadnij liczbe od 1 do 100. Trwa losowanie...");
        int randomNumber = random.nextInt(100) + 1;
        int attempts = 0;
        System.out.println("Liczba wylosowana.");
        while (true){
            int yourGuess = input.nextInt();
        if (yourGuess < randomNumber) {
            System.out.println("Za mala liczba.");
            attempts++;
        } else if (yourGuess > randomNumber) {
            System.out.println("Za duza liczba.");
            attempts++;
        } else {
            attempts++;
            System.out.println("Gratulacje!");
            System.out.println("Liczba prob: " + attempts);
            break;
        }
        }
    }
}
