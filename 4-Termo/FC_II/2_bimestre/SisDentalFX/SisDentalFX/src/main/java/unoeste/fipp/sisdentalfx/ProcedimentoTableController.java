import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import unoeste.fipp.sisdentalfx.db.entities.Procedimento;
import unoeste.fipp.sisdentalfx.db.repositories.ProcedimentoDAL;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class ProcedimentoTableController implements  {

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

@FXML
void onNovoProcedimento(ActionEvent event) {

}

@FXML
void onPesquisar(KeyEvent event) {

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
}
