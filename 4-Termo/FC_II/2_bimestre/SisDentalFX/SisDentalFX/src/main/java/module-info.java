module unoeste.fipp.sisdentalfx {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.desktop;

    opens unoeste.fipp.sisdentalfx.db.entities to javafx.fxml;
    opens unoeste.fipp.sisdentalfx to javafx.fxml;
    exports unoeste.fipp.sisdentalfx;

    exports unoeste.fipp.sisdentalfx.db.entities;

    exports unoeste.fipp.sisdentalfx.db.repositories;
}