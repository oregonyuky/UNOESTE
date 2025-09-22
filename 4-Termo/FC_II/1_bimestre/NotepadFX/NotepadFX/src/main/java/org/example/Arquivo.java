package org.example;

import java.io.RandomAccessFile;

public class Arquivo {
    public static String abrir(String arquivo){
        String sDados;
        try{
            byte[] dados;
            RandomAccessFile raf=new RandomAccessFile(arquivo,"r");
            dados=new byte[(int)raf.length()];
            raf.readFully(dados);
            sDados=new String(dados);
        }catch (Exception e){
            sDados="Erro ao processar o arquivo";
        }
        return sDados;
    }
    public static boolean salvar(String arquivo, String conteudo){
        try{
            RandomAccessFile raf = new RandomAccessFile(arquivo, "rw");
            raf.setLength(0);
            raf.writeBytes(conteudo);
            raf.close();
            return true;
        } catch(Exception e){
            System.err.println("Erro ao salvar o arquivo: " + e.getMessage());
            return false;
        }
    }
}
