module com.example.paintfx {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;
    requires javafx.swing;
    requires ij;


    opens com.example.paintfx to javafx.fxml;
    exports com.example.paintfx;
}