module com.example.nodepadfx {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.nodepadfx to javafx.fxml;
    exports com.example.nodepadfx;
}