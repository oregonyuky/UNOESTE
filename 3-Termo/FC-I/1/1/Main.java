import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // //Matematica matematica = new Matematica(); Método estático não precisa criar um objeto do tipo classe Matemática, ele já acessa a classe diretamente
        // // long res = Matematica.potencia(2,3);
        // // System.out.println("Resultado: " + res);
         Produto produto1 = new Produto("Café");
         Produto produto2 = new Produto("Picanha");
         Produto produto3 = new Produto("Ovo");
        // System.out.println(produto3.getNome()+": codigo " + produto2.getCodigo());
        // System.out.println(Produto.sequencia);

        // System.out.println(Matematica.PI);

        List <Produto>produtoList = new ArrayList(); //Lista só aceita produto da classe <Produto>
        produtoList.add(produto1);
        produtoList.add(produto2);
        produtoList.add(produto3);
        produtoList.add(2, new Produto("Azeite")); //define posição para adicionar o azeite
        produtoList.set(0, new Produto("Carne")); //substituiu o elemento nessa posição para adicionar o novo
        if(!produtoList.contains(produto1))
            produtoList.add(produto1);

        System.out.println("Quantidade de produtos: "+ produtoList.size());
        for (int i = 0; i < produtoList.size(); i++) 
        {
            System.out.println(produtoList.get(i).getCodigo()+" "+produtoList.get(i).getNome()); //produtoList[i].nome;
        }
        produtoList.remove(0);
        for(Produto p:produtoList)
            System.out.println(p.getNome());
        
        produtoList.toArray(); //cria um vetor com o total de elementos que possui e retorna o vetor

        produtoList.sort(new Comparator<Produto>() {
            @Override
            public int compare(Produto o1, Produto o2)
            {
                return o1.getNome().compareTo(o2.getNome()); //o1.getCodigo()-o2.getCodigo(); esse ordena pelo codigo numero
            }
        });

        for(Produto p:produtoList)
            System.out.println(p.getCodigo() + " " + p.getNome()+ " ");
    }
}
