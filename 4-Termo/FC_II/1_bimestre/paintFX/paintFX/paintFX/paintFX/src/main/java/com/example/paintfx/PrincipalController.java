package com.example.paintfx;

import com.example.paintfx.util.ImageJConverter;
import com.example.paintfx.util.imageConverter;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.SnapshotParameters;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.FileChooser;

import javax.imageio.ImageIO;
import java.io.File;
import java.io.IOException;

import ij.IJ;
import ij.ImagePlus;
import ij.process.ImageProcessor;
import javafx.embed.swing.SwingFXUtils;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.awt.image.BufferedImage;

public class PrincipalController{

    @FXML
    public ImageView imageView;
    public ToggleButton tbFormas;
    public BorderPane painel;
    public Label lbFileImage;
    public Slider slZoom;
    private double startX, startY;

    @FXML
    private StackPane stackPane;
    @FXML
    private Canvas canvas;
    @FXML
    private MenuItem menuItemSalvar;
    @FXML
    private Image imagemOriginal;
    private File arquivoAtual = null;
    private boolean imagemAlterada = false;
    private GraphicsContext gc;

    @FXML private MenuItem menuItemGaussian;
    @FXML private MenuItem menuItemSharpen;
    @FXML private MenuItem menuItemEqualize;
    @FXML private MenuItem menuItemNoise;
    @FXML private MenuItem menuItemEdgeDetect;

    @FXML private MenuItem menuItemEditarTonsCinza;
    @FXML private MenuItem menuItemEditarPretoBranco;
    @FXML private MenuItem menuItemEditarInverter;
    @FXML private MenuItem menuItemEspelharH;
    @FXML private MenuItem menuItemEspelharV;

    @FXML
    public void initialize() {
        gc = canvas.getGraphicsContext2D();
        gc.setLineWidth(3.0);
        gc.setStroke(Color.RED);
        setImageJMenuItemsEnabled(false);
        canvas.setOnMousePressed(e -> {
            startX = e.getX();
            startY = e.getY();

            if (FormasController.forma == 4) {
                gc.beginPath();
                gc.moveTo(startX, startY);
                gc.stroke();
                setImagemAlterada(true);
            }
        });

        canvas.setOnMouseDragged(e -> {
            if (FormasController.forma == 4) {
                gc.lineTo(e.getX(), e.getY());
                gc.stroke();
                setImagemAlterada(true);
            }
        });

        canvas.setOnMouseReleased(e -> {
            double endX = e.getX();
            double endY = e.getY();

            switch (FormasController.forma) {
                case 1 -> {
                    double w = Math.abs(endX - startX);
                    double h = Math.abs(endY - startY);
                    gc.strokeOval(Math.min(startX, endX), Math.min(startY, endY), w, h);
                }
                case 2 -> {
                    double w = Math.abs(endX - startX);
                    double h = Math.abs(endY - startY);
                    gc.strokeRect(Math.min(startX, endX), Math.min(startY, endY), w, h);
                }
                case 3 -> {
                    TextInputDialog dialog = new TextInputDialog("Digite aqui");
                    dialog.setTitle("Inserir Texto");
                    dialog.setHeaderText("Digite o texto que deseja desenhar:");
                    dialog.setContentText("Texto:");
                    dialog.showAndWait().ifPresent(text -> gc.fillText(text, startX, startY));
                }
                case 4 -> {
                }
            }
        });

        stackPane.widthProperty().addListener((obs, oldV, newV) -> ajustarTamanhoCanvas());
        stackPane.heightProperty().addListener((obs, oldV, newV) -> ajustarTamanhoCanvas());
    }
    private void setImageJMenuItemsEnabled(boolean enabled) {
        menuItemGaussian.setDisable(!enabled);
        menuItemSharpen.setDisable(!enabled);
        menuItemEqualize.setDisable(!enabled);
        menuItemNoise.setDisable(!enabled);
        menuItemEdgeDetect.setDisable(!enabled);
        menuItemEditarTonsCinza.setDisable(!enabled);
        menuItemEditarPretoBranco.setDisable(!enabled);
        menuItemEditarInverter.setDisable(!enabled);
        menuItemEspelharH.setDisable(!enabled);
        menuItemEspelharV.setDisable(!enabled);
    }


    private void ajustarTamanhoCanvas() {
        double w = stackPane.getWidth();
        double h = stackPane.getHeight();
        canvas.setWidth(w);
        canvas.setHeight(h);
    }

    private void setImagemAlterada(boolean v) {
        imagemAlterada = v;
        menuItemSalvar.setDisable(!imagemAlterada);
    }
    public void onAbrir(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Abrir imagem");
        fileChooser.setInitialDirectory(new File(System.getProperty("user.home")));

        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Imagens (*.png, *.jpg, *.jpeg, *.bmp, *.gif)", "*.png", "*.jpg", "*.jpeg", "*.bmp", "*.gif"),
                new FileChooser.ExtensionFilter("PNG (*.png)", "*.png"),
                new FileChooser.ExtensionFilter("JPG (*.jpg)", "*.jpg"),
                new FileChooser.ExtensionFilter("JPEG (*.jpeg)", "*.jpeg"),
                new FileChooser.ExtensionFilter("BMP (*.bmp)", "*.bmp"),
                new FileChooser.ExtensionFilter("GIF (*.gif)", "*.gif")
        );

        File file = fileChooser.showOpenDialog(null);
        if (file != null) {
            try {
                BufferedImage bufferedImage = ImageIO.read(file);
                if (bufferedImage == null) {
                    throw new IOException("Formato de imagem não suportado!");
                }

                Image image = SwingFXUtils.toFXImage(bufferedImage, null);
                imageView.setImage(image);
                imagemOriginal = image;
                arquivoAtual = file;
                setImagemAlterada(false);
                setImageJMenuItemsEnabled(true);

                // limpa qualquer desenho anterior
                gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

                // ajusta o tamanho do canvas para o tamanho da imagem original
                canvas.setWidth(image.getWidth());
                canvas.setHeight(image.getHeight());

                lbFileImage.setText(file.getAbsolutePath() +
                        " (" + (int) image.getWidth() + " x " + (int) image.getHeight() + ")");

                slZoom.setMin(0);
                slZoom.setMax(100);
                slZoom.setValue(100);

                slZoom.valueProperty().addListener((obs, oldVal, newVal) -> {
                    double escala = newVal.doubleValue() / 100.0;
                    imageView.setFitWidth(image.getWidth() * escala);
                    imageView.setFitHeight(image.getHeight() * escala);

                    // se quiser que o canvas acompanhe a escala:
                    canvas.setWidth(image.getWidth() * escala);
                    canvas.setHeight(image.getHeight() * escala);
                });

                // aplica tamanho inicial (100%)
                imageView.setFitWidth(image.getWidth());
                imageView.setFitHeight(image.getHeight());

            } catch (IOException e) {
                Alert alert = new Alert(Alert.AlertType.ERROR,
                        "Erro ao carregar imagem: " + e.getMessage(),
                        ButtonType.OK);
                alert.showAndWait();
            }
        }
    }



    public void onFechar(ActionEvent actionEvent) {
        if (imageView.getImage() == null && !imagemAlterada) {
            setImageJMenuItemsEnabled(false);

            Platform.exit();
            return;
        }

        if (imagemAlterada) {
            Alert alert = new Alert(Alert.AlertType.CONFIRMATION,
                    "Houve alterações na imagem. Deseja salvar antes de sair?",
                    ButtonType.YES, ButtonType.NO, ButtonType.CANCEL);
            ButtonType result = alert.showAndWait().orElse(ButtonType.CANCEL);
            if (result == ButtonType.YES) {
                onSalvar(actionEvent);
                Platform.exit();
            } else if (result == ButtonType.NO) {
                Platform.exit();
            }
            // CANCEL -> não faz nada
        } else {
            Platform.exit();
        }
    }

    public void onTonsCinza(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(imageConverter.toGrayScale(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onEspelharVertical(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(imageConverter.toEspelhoVertical(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onEspelharHorizontal(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(imageConverter.toEspelhoHorizontal(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onInverterCores(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(imageConverter.toInverterCores(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onPretoBranco(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(imageConverter.toPretoBranco(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onSalvar(ActionEvent actionEvent) {
        if (imageView.getImage() == null) {
            Alert alert = new Alert(Alert.AlertType.WARNING, "Nenhuma imagem carregada!", ButtonType.OK);
            alert.showAndWait();
            return;
        }

        if (arquivoAtual == null) {
            onSalvarComo(actionEvent);
            return;
        }

        try {
            aplicarDesenhoNaImagem();
            String ext = getExtension(arquivoAtual.getName());
            ImageIO.write(javafx.embed.swing.SwingFXUtils.fromFXImage(imageView.getImage(), null), ext, arquivoAtual);
            setImagemAlterada(false);
        } catch (IOException e) {
            e.printStackTrace();
            Alert alert = new Alert(Alert.AlertType.ERROR, "Erro ao salvar imagem!\n" + e.getMessage(), ButtonType.OK);
            alert.showAndWait();
        }
    }


    public void onSalvarComo(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Salvar imagem como...");
        fileChooser.setInitialFileName("desenho.png");
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("PNG (*.png)", "*.png"),
                new FileChooser.ExtensionFilter("JPG (*.jpg)", "*.jpg"),
                new FileChooser.ExtensionFilter("JPEG (*.jpeg)", "*.jpeg"),
                new FileChooser.ExtensionFilter("BMP (*.bmp)", "*.bmp"),
                new FileChooser.ExtensionFilter("GIF (*.gif)", "*.gif")
        );

        File file = fileChooser.showSaveDialog(null);
        if (file != null) {

            String ext = getExtension(file.getName());

            if (!file.getName().contains(".")) {
                FileChooser.ExtensionFilter selected = fileChooser.getSelectedExtensionFilter();
                if (selected != null && !selected.getExtensions().isEmpty()) {
                    String defaultExt = selected.getExtensions().get(0).replace("*.", "");
                    file = new File(file.getAbsolutePath() + "." + defaultExt);
                    ext = defaultExt;
                } else {
                    file = new File(file.getAbsolutePath() + ".png");
                    ext = "png";
                }
            }


            if (file.exists()) {
                Alert overwrite = new Alert(Alert.AlertType.CONFIRMATION,
                        "Arquivo já existe. Deseja sobrescrever?",
                        ButtonType.YES, ButtonType.NO);
                ButtonType ans = overwrite.showAndWait().orElse(ButtonType.NO);
                if (ans != ButtonType.YES) return;
            }

            try {

                WritableImage snapshot = new WritableImage(
                        (int) stackPane.getWidth(),
                        (int) stackPane.getHeight()
                );
                stackPane.snapshot(null, snapshot);

                BufferedImage bufferedImage = SwingFXUtils.fromFXImage(snapshot, null);

                // Converte para RGB se for JPG/JPEG/BMP
                if (ext.equalsIgnoreCase("jpg") || ext.equalsIgnoreCase("jpeg") || ext.equalsIgnoreCase("bmp")) {
                    BufferedImage rgbImage = new BufferedImage(
                            bufferedImage.getWidth(),
                            bufferedImage.getHeight(),
                            BufferedImage.TYPE_INT_RGB
                    );
                    rgbImage.createGraphics().drawImage(bufferedImage, 0, 0, java.awt.Color.WHITE, null);
                    bufferedImage = rgbImage;
                }

                ImageIO.write(bufferedImage, ext, file);

                arquivoAtual = file;
                setImagemAlterada(false);

                Alert alert = new Alert(Alert.AlertType.INFORMATION, "Imagem salva com sucesso!", ButtonType.OK);
                alert.showAndWait();

            } catch (IOException e) {
                e.printStackTrace();
                Alert alert = new Alert(Alert.AlertType.ERROR,
                        "Erro ao salvar imagem!\n" + e.getMessage(),
                        ButtonType.OK);
                alert.showAndWait();
            }
        }
    }



    private String getExtension(String filename) {
        int dotIndex = filename.lastIndexOf('.');
        if (dotIndex > 0 && dotIndex < filename.length() - 1) {
            return filename.substring(dotIndex + 1).toLowerCase();
        }
        return "png";
    }

    public void onInformacoes(ActionEvent actionEvent) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Sobre");
        alert.setHeaderText("PaintFX - Editor de Imagens");
        alert.setContentText(
                "Versão: 1.0\n" +
                        "Desenvolvedor:\n" +
                        "- Felipe Akio Nishimura\n" +
                        "- Termo: 4 termo\n"  +
                        "- RA: 102418462\n" +
                        "- Idade: 19 anos\n" +
                        "Aplicativo desenvolvido em JavaFX\n" +
                        "para edição e processamento de imagens."
        );
        alert.showAndWait();
    }
    private void aplicarDesenhoNaImagem() {
        if (stackPane != null && imageView.getImage() != null) {
            WritableImage snapshot = new WritableImage((int) stackPane.getWidth(), (int) stackPane.getHeight());
            stackPane.snapshot(new SnapshotParameters(), snapshot);

            imageView.setImage(snapshot);
            gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
        }
    }
    public void onGaussianBlur(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(ImageJConverter.gaussianBlur(imageView.getImage(), 2.0));
        setImagemAlterada(true);
    }

    public void onSharpen(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(ImageJConverter.sharpen(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onEdgeDetect(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(ImageJConverter.findEdges(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onEqualizeHistogram(ActionEvent actionEvent) {
        if (imageView.getImage() == null) return;
        imageView.setImage(ImageJConverter.equalizeHistogram(imageView.getImage()));
        setImagemAlterada(true);
    }

    public void onNoise(ActionEvent actionEvent) throws Exception{
        Stage stage=new Stage();
        FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("noise-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load());
        stage.setTitle("Noise");
        stage.setScene(scene);
        stage.initStyle(StageStyle.UTILITY);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.setResizable(false);
        stage.showAndWait();
        int fator=NoiseController.fator;
        if(fator!=-1)
            imageView.setImage(ImageJConverter.noise(imageView.getImage(), 10));
    }

    public void onPainelFormas(ActionEvent actionEvent) throws Exception{
        if(tbFormas.isSelected()){
            FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("formas-view.fxml"));
            VBox vBox=fxmlLoader.load();
            painel.setRight(vBox);
        }
        else
            painel.setRight(null);
    }

    public void onReload(ActionEvent actionEvent) {
        if (imagemOriginal != null) {
            imageView.setImage(imagemOriginal);
            gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight()); // limpa os desenhos
            setImagemAlterada(false);

            Alert alert = new Alert(Alert.AlertType.INFORMATION,
                    "Imagem restaurada para o estado original!",
                    ButtonType.OK);
            alert.showAndWait();
        } else {
            Alert alert = new Alert(Alert.AlertType.WARNING,
                    "Nenhuma imagem aberta para recarregar.",
                    ButtonType.OK);
            alert.showAndWait();
        }
    }



}
