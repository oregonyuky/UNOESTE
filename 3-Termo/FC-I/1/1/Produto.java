public class Produto {
    private int codigo;
    private String nome;
    static public int sequencia=1000;
    public Produto(String nome)
    {
        this.codigo = sequencia++;
        this.nome = nome;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
}
