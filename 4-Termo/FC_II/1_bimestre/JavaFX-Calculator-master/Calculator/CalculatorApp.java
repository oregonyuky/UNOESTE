package Calculator;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class CalculatorApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Calculator");
        primaryStage.setScene(new Scene(root, 300, 375));
        primaryStage.show();
        primaryStage.getIcons().add(new Image("file:C:\\Java Programs\\Calculator\\icon.png"));
        primaryStage.setResizable(false);
    }


    public static void main(String[] args) {
        launch(args);
    }
}
