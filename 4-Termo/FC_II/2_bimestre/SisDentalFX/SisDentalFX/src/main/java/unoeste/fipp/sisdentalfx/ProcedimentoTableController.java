package unoeste.fipp.sisdentalfx;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import javafx.stage.Modality;
import javafx.stage.Stage;
import unoeste.fipp.sisdentalfx.db.entities.Procedimento;
import unoeste.fipp.sisdentalfx.db.repositories.ProcedimentoDAL;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class ProcedimentoTableController implements Initializable {

    @FXML
    private TableColumn<Procedimento, String> colDesc;

    @FXML
    private TableColumn<Procedimento, Integer> colID;

    @FXML
    private TableColumn<Procedimento, Double> colTempo;

    @FXML
    private TableColumn<Procedimento, Double> colValor;

    @FXML
    private TableView<Procedimento> tableView;

    @FXML
    private TextField tfPesquisa;

    @FXML
    void onFechar(ActionEvent event) {
        tfPesquisa.getScene().getWindow().hide();
    }
    public static Procedimento procedimento = null;
    @FXML
    void onNovoProcedimento(ActionEvent event) {
        try {
            Stage stage = new Stage();
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("procedimento-form-view.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            //stage.getTitle("Procedimento");
            stage.setScene(scene);
            stage.initModality(Modality.APPLICATION_MODAL);
            stage.showAndWait();
            carregarTabela("");
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    @FXML
    void onPesquisar(KeyEvent event) {
        carregarTabela("pro_desc LIKE '%" + tfPesquisa.getText()+"%'");
    }
        @Override
        public void initialize(URL url, ResourceBundle resourceBundle){
        colID.setCellValueFactory(new PropertyValueFactory<>("id"));
        colDesc.setCellValueFactory(new PropertyValueFactory<>("descr"));
        colTempo.setCellValueFactory(new PropertyValueFactory<>("tempo"));
        colValor.setCellValueFactory(new PropertyValueFactory<>("valor"));
        carregarTabela("");
    }
    private void carregarTabela(String filtro){
        ProcedimentoDAL dal = new ProcedimentoDAL();
        List<Procedimento> procedimentoList = dal.get(filtro);
        tableView.setItems(FXCollections.observableArrayList(procedimentoList));
    }
    @FXML
    void onAlterar(ActionEvent event) {
        if(tableView.getSelectionModel().getSelectedItem()!=null){
            procedimento = tableView.getSelectionModel().getSelectedItem();
            try {
                Stage stage = new Stage();
                FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("procedimento-form-view.fxml"));
                Scene scene = new Scene(fxmlLoader.load());
                //stage.getTitle("Procedimento");
                stage.setScene(scene);
                stage.initModality(Modality.APPLICATION_MODAL);
                stage.showAndWait();
                carregarTabela("");
                procedimento = null;
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }

    @FXML
    void onApagar(ActionEvent event) {
        if(tableView.getSelectionModel().getSelectedItem()!=null){
            Procedimento procedimento = tableView.getSelectionModel().getSelectedItem();
        }
    }
}
