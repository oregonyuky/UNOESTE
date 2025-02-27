import java.util.Scanner;
public class encontrar_E {
    public static void main(String[] args) {
        String nome="Universidade Unoeste";
        String nome2="unoeste";
        if(nome.toUpperCase().endsWith("oeste".toUpperCase()))
            System.out.println(nome);

        if (nome.toUpperCase().contains("Dade".toUpperCase()))
            System.out.println("contém");

        String placa = "GGG-0888";
        //regex
        if (placa.matches("[a-zA-Z]{3}-[0-9]{1}[A-Z0-9]{1}[0-9]{2}"))
            System.out.println("É uma placa!");

        int num=0;
        for(int i=0; i<placa.length();i++)
            //if(placa.charAt(i)>='0' && placa.charAt(i)<='9')
            if (String.valueOf(placa.charAt(i)).matches("[AEIOU]")) //converteu caracter para string para poder comparar se possui as vogais
                num++;
        System.out.println(num);

        nome="Frederico Gonçalves Bezerra";
        System.out.println(nome.split(" "));

        //nome=nome.replaceAll("[\s]", "");
        System.out.println(nome);
        
        Scanner leitor = new Scanner(System.in);
        String str = leitor.nextLine();
        String str1 = leitor.nextLine();

        String str, str1;
        int size = str.length(), i=0, index=0, sum=0;
      
        String str = leitor.nextLine();
        String str1 = leitor.nextLine();

        int size = str.length(), i=0, index=0, sum=0;
        while(size-- > 0){
            if(str.charAt(i)==str1.charAt(index)){
                index++;
                if(str1.length()==index){
                    int tam = i-str1.length()+1;
                    System.out.println("index: " + tam);
                    sum++;
                    index = 0;
                }
            }
            else
                index=0;
            if(i < str.length()-1) i++;
        }
        System.out.println("Quantidade: " + sum);
        
        System.out.println(nome.lastIndexOf("e")); //desafio usar index pra achar onde estão todos E.

        System.out.println(nome.substring(2,3));

        System.out.println(nome.charAt(3));
        
        String frase = "Em sua fala contou sobre o processo da construção do Hospital de Prudente";
        char[] fraseCaracter = frase.toCharArray(); //converteu string para vetor
        for(int i=0; i<fraseCaracter.length;i++)
            System.out.println(fraseCaracter[i]);

        String str = new String(fraseCaracter); //converteu vetor para string
    }
}
