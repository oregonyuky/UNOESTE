package com.example.paintfx;
import javafx.scene.input.MouseEvent;
public class FormasController {
    public static int forma=-1;
    //1: circulo 2: retangulo 3: texto 4: mao livre
    public void onCirculo(MouseEvent mouseEvent) {
        forma=1;
    }
    public void onTexto(MouseEvent mouseEvent) {
        forma=3;
    }
    public void onRetangulo(MouseEvent mouseEvent) {
        forma=2;
    }
    public void onCaneta(MouseEvent mouseEvent) {
        forma=4;
    }
}
