import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class PassGen {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        Random random = new Random();

        String chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        ArrayList<String> passwords = new ArrayList<>();
        System.out.println("Dlugosc twojego hasla:\n");
        int length = input.nextInt();
        System.out.println("Ilosc hasel:\n");
        int quantity = input.nextInt();

        for (int i = 0; i < quantity; i++){
            String pass = "";
            for (int j = 0; j < length; j++){
                int index = random.nextInt(chars.length());
                pass += chars.charAt(index);
            }
            passwords.add(pass);
        }
        System.out.println("Twoje hasla:\n");
        for (String pass : passwords){
            System.out.println(pass);
        }
        input.close();

    }
}
