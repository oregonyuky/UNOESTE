package unoeste.fipp.sisdentalfx.db.entities;

import unoeste.fipp.sisdentalfx.db.repositories.ProcedimentoDAL;

public class Procedimento {
    private int id;
    private String descr;
    private double tempo;
    private double valor;

    public Procedimento(){
        this(0,"",0,0);
    }

    public Procedimento(int id, String a, double b, double c) {
        this.id = id;
        this.descr = a;
        this.tempo = b;
        this.valor = c;
    }
    public Procedimento(String descr, double tempo, double valor) {
        this(0,descr,tempo,valor);
    }
    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public double getTempo() {
        return tempo;
    }

    public void setTempo(double tempo) {
        this.tempo = tempo;
    }

    public String getDescr() {
        return descr;
    }

    public void setDescr(String descr) {
        this.descr = descr;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
