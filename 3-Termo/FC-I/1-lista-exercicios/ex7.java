import java.util.Scanner;
public class ex7{
    public static int contar_vogais(String str){
        int count=0;
        String vogais = "aeiouAEIOU";
        for(char c : str.toCharArray()){
            if(vogais.indexOf(c) != -1)
                count++;
        }
        return count;
    }
    public static int contarDigitos(String str){
        int count=0;
        for(char c : str.toCharArray()){
            if(Character.isDigit(c))
                count++;
        }
        return count;
    }
    public static boolean palindromo(String str){
        String strN = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        int left=0, right=strN.length()-1;
        while(left < right){
            if(strN.charAt(left) != strN.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] args){
        Scanner leitura = new Scanner(System.in);
        System.out.println("Digite uma string: ");
        String str = leitura.nextLine();
        leitura.close();
        int tamanho = str.length();
        String strN = str.toUpperCase();
        int numero_vogais = contar_vogais(str);
        boolean comeca_com_uno = str.toUpperCase().startsWith("UNO");
        boolean termina_com_ste = str.toUpperCase().endsWith("STE");
        int digitCount = contarDigitos(str);
        boolean palindromo = palindromo(str);
        System.out.println("Numero de caracteres: " + tamanho);
        System.out.println("String em maiusculas: " + strN);
        System.out.println("Numero de vogais: " + numero_vogais);
        System.out.println("Comeca com UNO: " + comeca_com_uno);
        System.out.println("Termina com STE: " + termina_com_ste);
        System.out.println("Numero de digitos: " + digitCount);
        System.out.println("E um palindromo: " + palindromo);
    }
}
