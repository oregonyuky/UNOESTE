import java.util.Scanner;
public class ex8{
    public static void main(String[] args){
        Scanner leitura = new Scanner(System.in);
        String nome = leitura.nextLine();
        leitura.close();
        String[] ignorar_palavras = {"e", "do", "da", "dos", "das", "de", "di", "du"};
        String[] palavra = nome.split(" ");
        String initial = "";
        for(String cada_palavra : palavra){
            boolean flag = false;
            for(String ignorar : ignorar_palavras){
                if(cada_palavra.equalsIgnoreCase(ignorar)){
                    flag = true;
                    break;   
                }
            }
            if(!flag && !cada_palavra.isEmpty())
                initial += Character.toUpperCase(cada_palavra.charAt(0));
        }
        System.out.println(initial);
    }
}
