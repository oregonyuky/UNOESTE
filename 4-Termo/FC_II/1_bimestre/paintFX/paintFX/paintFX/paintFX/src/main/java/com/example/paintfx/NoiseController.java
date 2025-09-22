package com.example.paintfx;

import javafx.event.ActionEvent;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Slider;
import java.util.ResourceBundle;

import java.net.URL;

public  class NoiseController implements Initializable {
    public Slider slNoise;
    public static int fator=-1;
    public Button btConfirmar;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle){
        slNoise.setValue(10);
    }
    public void onConfirmar(ActionEvent actionEvent) {
        fator=(int)slNoise.getValue();
        slNoise.getScene().getWindow().hide();
    }
}
