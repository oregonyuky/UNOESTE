package unoeste.fipp.sisdentalfx;

import javafx.application.Platform;
import javafx.fxml.Initializable;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import unoeste.fipp.sisdentalfx.db.entities.Procedimento;
import unoeste.fipp.sisdentalfx.db.repositories.ProcedimentoDAL;
import unoeste.fipp.sisdentalfx.util.MaskFieldUtil;

import java.net.URL;
import java.util.ResourceBundle;

public class ProcedimentoFormController implements Initializable {
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle){
        if(ProcedimentoTableController.procedimento!=null){
            Procedimento procedimento = ProcedimentoTableController.procedimento;
            tfDesc.setText(procedimento.getDescr());
            tfPreco.setText(""+procedimento.getValor());
            tfID.setText(""+procedimento.getId());
            tfTempo.setValue(procedimento.getTempo());
        }
        Platform.runLater(()->{tfDesc.requestFocus();});
        MaskFieldUtil.monetaryField(tfPreco);
    }
    @FXML
    private Button btCancelar;

    @FXML
    private Button btConfirmar;

    @FXML
    private TextField tfDesc;

    @FXML
    private TextField tfID;

    @FXML
    private TextField tfPreco;

    @FXML
    private Slider tfTempo;

    @FXML
    void onCancelar(ActionEvent event) {
        tfPreco.getScene().getWindow().hide();
    }

    @FXML
    void onConfirmar(ActionEvent event) {
        Procedimento procedimento = new Procedimento(tfDesc.getText(), tfTempo.getValue(), Double.parseDouble(tfPreco.getText().replace(",", ".")));
        ProcedimentoDAL dal = new ProcedimentoDAL();
        if(!tfID.getText().isEmpty()){
            procedimento.setId(Integer.parseInt(tfID.getText()));
            if(!dal.alterar(procedimento)){
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setContentText("Erro ao gravar o procedimento");
                alert.showAndWait();
            }
        }
        else
            if(!dal.gravar(procedimento)){
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setContentText("Erro ao gravar o procedimento");
                alert.showAndWait();
            }
            tfPreco.getScene().getWindow().hide();
    }

}
