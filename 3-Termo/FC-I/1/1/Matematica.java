public class Matematica{
    final public static double PI=3.1415; //final define como constante, não pode mudar nunca
    //nao pode acessar atributos
    //nao pode executar outro método que não seja estático
    static public long potencia(int base, int expoente){
        long res=1;
        for(int i=0; i<expoente; i++)
            res*=base;
        return res;
    }
}