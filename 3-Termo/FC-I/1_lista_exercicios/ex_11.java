import java.util.regex.*;
public class ex11{
    public static String validarString(String input) {
        String regexNome = "^[A-ZÁÉÍÓÚÂÊÎÔÛÄËÏÖÜ][a-záéíóúâêîôûäëïöü]+( [A-ZÁÉÍÓÚÂÊÎÔÛÄËÏÖÜ][a-záéíóúâêîôûäëïöü]+)+$";
        String regexEmail = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
        String regexVariavel = "^[a-zA-Z_$][a-zA-Z0-9_$]*$";
        String regexPlaca = "^[A-Z]{3}-\\d{1}[A-Z0-9]?\\d{2}$";
        if (input.matches(regexNome)) {
            return "NOME";
        }
        if (input.matches(regexEmail)) {
            return "EMAIL";
        }
        if (input.matches(regexVariavel)) {
            return "VARIAVEL";
        }
        if (input.matches(regexPlaca)) {
            return "PLACA";
        }
        return "DESCONHECIDO";
    }
    public static void main(String[] args) {
        System.out.println(validarString("João Silva"));           // NOME
        System.out.println(validarString("joao.silva@example.com")); // EMAIL
        System.out.println(validarString("variavel123"));          // VARIAVEL
        System.out.println(validarString("ABC-1X23"));             // PLACA
        System.out.println(validarString("invalido@exemplo"));     // DESCONHECIDO
    }
}

