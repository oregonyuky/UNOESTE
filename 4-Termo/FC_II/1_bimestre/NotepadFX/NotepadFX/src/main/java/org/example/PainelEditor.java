package org.example;

import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.stage.FileChooser;

import java.io.File;

public class PainelEditor extends BorderPane {
    private TextArea textArea;
    private Button btNovo, btAbrir, btSalvar;
    public PainelEditor(){
        inicializarComponentes();
        this.setCenter(textArea);
        HBox hBox=new HBox();
        hBox.getChildren().addAll(btNovo,btAbrir,btSalvar);
        this.setBottom(hBox);
        hBox.setSpacing(47);
        hBox.setAlignment(Pos.CENTER);
        hBox.setPrefHeight(45);
        hBox.setStyle("-fx-background-color:#FFA500");
    }
    private void inicializarComponentes(){
        textArea=new TextArea("Digite algo");
        btNovo=new Button("     Novo    ");
        btAbrir=new Button("    Abrir   ");
        btSalvar=new Button("   Salvar  ");
        //criar os eventos
        btNovo.setOnAction(e->{textArea.clear();textArea.requestFocus();});
        btAbrir.setOnAction(e->{carregarArquivo();});
        btSalvar.setOnAction(e->{salvarArquivo();});
    }
    private void carregarArquivo() {
        FileChooser fileChooser=new FileChooser();
        fileChooser.setInitialDirectory(new File("D://"));
        /* configurar para mostrar somente .txt, .java, .html*/
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Arquivos de Texto", "*.txt"),
                new FileChooser.ExtensionFilter("Arquivos Java", "*.java"),
                new FileChooser.ExtensionFilter("Arquivos HTML", "*.html"),
                new FileChooser.ExtensionFilter("Todos os Arquivos", "*.*")
        );
        File arq=fileChooser.showOpenDialog(null);
        if(arq!=null){
            textArea.setText(Arquivo.abrir(arq.getAbsolutePath()));
        }
    }
    private void salvarArquivo() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Salvar Arquivo");
        fileChooser.setInitialDirectory(new File("D://"));
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Arquivos de Texto", "*.txt"),
                new FileChooser.ExtensionFilter("Arquivos Java", "*.java"),
                new FileChooser.ExtensionFilter("Arquivos HTML", "*.html"),
                new FileChooser.ExtensionFilter("Todos os Arquivos", "*.*")
        );
        File arq = fileChooser.showSaveDialog(null);
        if (arq != null) {
            boolean salvo = Arquivo.salvar(arq.getAbsolutePath(), textArea.getText());
            if (salvo) {
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Sucesso");
                alert.setHeaderText(null);
                alert.setContentText("Arquivo salvo com sucesso!");
                alert.showAndWait();
            } else {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Erro");
                alert.setHeaderText(null);
                alert.setContentText("Ocorreu um erro ao salvar o arquivo.");
                alert.showAndWait();
            }
        }
    }
}
