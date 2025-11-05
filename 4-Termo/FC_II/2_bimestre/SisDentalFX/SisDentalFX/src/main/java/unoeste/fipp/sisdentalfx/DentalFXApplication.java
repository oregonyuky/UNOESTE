package unoeste.fipp.sisdentalfx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import java.io.IOException;

public class DentalFXApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        // 🔹 Abre conexão com o banco antes de carregar o FXML
        boolean conectado = SingletonDB.conectar();
        if (!conectado) {
            System.out.println("Erro ao conectar com o banco de dados!");
            return;
        }

        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("procedimento-table-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setScene(scene);
        stage.show();
    }

}
