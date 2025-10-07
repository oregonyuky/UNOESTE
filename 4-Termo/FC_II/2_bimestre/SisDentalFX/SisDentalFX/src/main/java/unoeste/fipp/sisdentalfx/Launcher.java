package unoeste.fipp.sisdentalfx;

import javafx.application.Application;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import javax.swing.*;

public class Launcher {
    public static void main(String[] args) {
        if(!SingletonDB.conectar()){
            int op=JOptionPane.showConfirmDialog(null,
                    "Problemas ao conectar com o banco: \n"+
                    SingletonDB.getConexao().getMensagemErro()+ "\n Deseja criar a base de dados?");
            if(op==JOptionPane.YES_OPTION){
                //criar a base de dados
                if(SingletonDB.criarBD("sisdentaldb")) {
                    //restaurar o script
                    if(SingletonDB.criarTabelas("sisdentaldb.sql","sisdentaldb"))
                        JOptionPane.showMessageDialog(null,"Base de dados restaurada\nExecute o sistema novamente");
                }
            }
        }
        else
            Application.launch(DentalFXApplication.class, args);
    }
}
