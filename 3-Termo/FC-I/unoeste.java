public class unoeste{
    public static void main(String[] args){
        string nome = "Universidade Unoeste";
        String nome2 = "unoeste";
        if(nome.toUpperCase().endsWith("oeste", toUpperCase()))
            System.out.println(nome);
        if(nome.toUpperCase().contains("Dade".toUpperCase()))
            System.out.println("contem");
        String placa = "GGG-0A88";
        if(placa.matches("[a-zA-Z]{3}-[0-9]{1}[A-Z0-9]{1}[0-9]{2}"))
            System.out.println("E uma placa");
        nome = nome.replace("e", "#");
        System.out.println(nome);
    }
}
