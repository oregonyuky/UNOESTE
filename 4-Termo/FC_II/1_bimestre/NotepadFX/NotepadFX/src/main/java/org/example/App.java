package org.example;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

import java.io.File;

public class App extends Application {
    @Override
    public void start(Stage stage) {
        PainelEditor painelEditor=new PainelEditor();
        Scene scene = new Scene(painelEditor, 800, 600);
        stage.setTitle("NotepadFX");
        stage.setScene(scene);
        stage.show();
        stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent windowEvent) {
                Alert alert=new Alert(Alert.AlertType.CONFIRMATION);
                alert.setContentText("Deseja fechar?");
                if(alert.showAndWait().get()== ButtonType.OK)
                    Platform.exit();
                else
                    windowEvent.consume();
            }
        });
    }

    public static void main(String[] args) {
        launch();
    }

}