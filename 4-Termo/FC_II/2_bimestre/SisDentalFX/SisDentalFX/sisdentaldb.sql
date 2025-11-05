--
-- PostgreSQL database dump
--

-- Dumped from database version 14.4
-- Dumped by pg_dump version 14.4

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: cons_mat; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cons_mat (cm_id integer NOT NULL, mat_id integer, con_id integer, cm_quant numeric(2,0));


ALTER TABLE public.cons_mat OWNER TO postgres;

CREATE SEQUENCE public.cons_mat_cm_id_seq AS integer START WITH 1 INCREMENT BY 1 NO MINVALUE NO MAXVALUE CACHE 1;

ALTER TABLE public.cons_mat_cm_id_seq OWNER TO postgres;

ALTER SEQUENCE public.cons_mat_cm_id_seq OWNED BY public.cons_mat.cm_id;

CREATE TABLE public.cons_proc (cp_is integer NOT NULL,con_id integer, pro_id integer, cp_quant numeric(2,0));

ALTER TABLE public.cons_proc OWNER TO postgres;

CREATE SEQUENCE public.cons_proc_cp_is_seq 
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.cons_proc_cp_is_seq OWNER TO postgres;

--
-- Name: cons_proc_cp_is_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.cons_proc_cp_is_seq OWNED BY public.cons_proc.cp_is;


--
-- Name: consulta; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.consulta (con_id integer NOT NULL,con_relato text,con_data date NOT NULL,con_horario numeric(2,0) NOT NULL, pac_id integer, den_id integer, con_efetivado boolean DEFAULT false);


ALTER TABLE public.consulta OWNER TO postgres;

--
-- Name: consulta_con_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.consulta_con_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.consulta_con_id_seq OWNER TO postgres;

--
-- Name: consulta_con_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.consulta_con_id_seq OWNED BY public.consulta.con_id;


--
-- Name: dentista; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.dentista (den_id integer NOT NULL, den_nome character varying(50) NOT NULL, den_cro numeric(5,0) NOT NULL, den_fone character varying(14), den_email character varying(100));


ALTER TABLE public.dentista OWNER TO postgres;

--
-- Name: dentista_den_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.dentista_den_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.dentista_den_id_seq OWNER TO postgres;

--
-- Name: dentista_den_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.dentista_den_id_seq OWNED BY public.dentista.den_id;


--
-- Name: material; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.material (mat_id integer NOT NULL,mat_desc character varying(20) NOT NULL, mat_preco numeric(9,2));


ALTER TABLE public.material OWNER TO postgres;

--
-- Name: material_mat_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.material_mat_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.material_mat_id_seq OWNER TO postgres;

--
-- Name: material_mat_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.material_mat_id_seq OWNED BY public.material.mat_id;

--
-- Name: paciente; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.paciente (pac_id integer NOT NULL, pac_cpf character varying(14), pac_nome character varying(50) NOT NULL,pac_cep character varying(9), pac_rua character varying(50), pac_numero character varying(10), pac_bairro character varying(30), pac_cidade character varying(20),pac_uf character varying(2),pac_fone character varying(14),pac_email character varying(100),pac_histo text);


ALTER TABLE public.paciente OWNER TO postgres;

--
-- Name: paciente_pac_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.paciente_pac_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.paciente_pac_id_seq OWNER TO postgres;

--
-- Name: paciente_pac_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.paciente_pac_id_seq OWNED BY public.paciente.pac_id;


--
-- Name: procedimento; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.procedimento (pro_id integer NOT NULL,pro_desc character varying(20) NOT NULL, pro_tempo numeric(2,0),pro_valor numeric(9,2));


ALTER TABLE public.procedimento OWNER TO postgres;

--
-- Name: procedimento_pro_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.procedimento_pro_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.procedimento_pro_id_seq OWNER TO postgres;

--
-- Name: procedimento_pro_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.procedimento_pro_id_seq OWNED BY public.procedimento.pro_id;


--
-- Name: usuario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.usuario (uso_id integer NOT NULL,uso_nome character varying(20) NOT NULL,uso_nivel numeric(1,0) NOT NULL,uso_senha character varying(10) NOT NULL);


ALTER TABLE public.usuario OWNER TO postgres;

--
-- Name: usuario_uso_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.usuario_uso_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.usuario_uso_id_seq OWNER TO postgres;

--
-- Name: usuario_uso_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.usuario_uso_id_seq OWNED BY public.usuario.uso_id;


--
-- Name: cons_mat cm_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_mat ALTER COLUMN cm_id SET DEFAULT nextval('public.cons_mat_cm_id_seq'::regclass);


--
-- Name: cons_proc cp_is; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_proc ALTER COLUMN cp_is SET DEFAULT nextval('public.cons_proc_cp_is_seq'::regclass);


--
-- Name: consulta con_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.consulta ALTER COLUMN con_id SET DEFAULT nextval('public.consulta_con_id_seq'::regclass);


--
-- Name: dentista den_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dentista ALTER COLUMN den_id SET DEFAULT nextval('public.dentista_den_id_seq'::regclass);


--
-- Name: material mat_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.material ALTER COLUMN mat_id SET DEFAULT nextval('public.material_mat_id_seq'::regclass);


--
-- Name: paciente pac_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.paciente ALTER COLUMN pac_id SET DEFAULT nextval('public.paciente_pac_id_seq'::regclass);


--
-- Name: procedimento pro_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.procedimento ALTER COLUMN pro_id SET DEFAULT nextval('public.procedimento_pro_id_seq'::regclass);


--
-- Name: usuario uso_id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usuario ALTER COLUMN uso_id SET DEFAULT nextval('public.usuario_uso_id_seq'::regclass);


--
-- Data for Name: cons_mat; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.cons_mat VALUES (1, 1, 1, 2);
INSERT INTO public.cons_mat VALUES (2, 2, 1, 1);


--
-- Data for Name: cons_proc; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: consulta; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.consulta VALUES (1, 'deu certo', '2023-10-09', 9, 1, 1, false);


--
-- Data for Name: dentista; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.dentista VALUES (1, 'Osvaldo Alberto', 1234, '18 9997-8998', 'osvaldo_dentista@gmail.com');


--
-- Data for Name: material; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.material VALUES (1, 'gase', 5.80);
INSERT INTO public.material VALUES (2, 'luvas', 0.90);


--
-- Data for Name: paciente; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.paciente VALUES (1, '122.555.998-36', 'Romulo Bezerra', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);


--
-- Data for Name: procedimento; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Data for Name: usuario; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- Name: cons_mat_cm_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.cons_mat_cm_id_seq', 2, true);


--
-- Name: cons_proc_cp_is_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.cons_proc_cp_is_seq', 1, false);


--
-- Name: consulta_con_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.consulta_con_id_seq', 1, true);


--
-- Name: dentista_den_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.dentista_den_id_seq', 1, true);


--
-- Name: material_mat_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.material_mat_id_seq', 2, true);


--
-- Name: paciente_pac_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.paciente_pac_id_seq', 1, true);


--
-- Name: procedimento_pro_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.procedimento_pro_id_seq', 1, false);


--
-- Name: usuario_uso_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.usuario_uso_id_seq', 1, false);


--
-- Name: cons_mat cons_mat_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_mat
    ADD CONSTRAINT cons_mat_pkey PRIMARY KEY (cm_id);


--
-- Name: cons_proc cons_proc_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_proc
    ADD CONSTRAINT cons_proc_pkey PRIMARY KEY (cp_is);


--
-- Name: consulta consulta_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.consulta
    ADD CONSTRAINT consulta_pkey PRIMARY KEY (con_id);


--
-- Name: dentista dentista_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dentista
    ADD CONSTRAINT dentista_pkey PRIMARY KEY (den_id);


--
-- Name: material material_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.material
    ADD CONSTRAINT material_pkey PRIMARY KEY (mat_id);


--
-- Name: paciente paciente_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.paciente
    ADD CONSTRAINT paciente_pkey PRIMARY KEY (pac_id);


--
-- Name: procedimento procedimento_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.procedimento
    ADD CONSTRAINT procedimento_pkey PRIMARY KEY (pro_id);


--
-- Name: usuario usuario_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usuario
    ADD CONSTRAINT usuario_pkey PRIMARY KEY (uso_id);


--
-- Name: cons_mat cons_mat_con_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_mat
    ADD CONSTRAINT cons_mat_con_id_fkey FOREIGN KEY (con_id) REFERENCES public.consulta(con_id) NOT VALID;


--
-- Name: cons_mat cons_mat_mat_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_mat
    ADD CONSTRAINT cons_mat_mat_id_fkey FOREIGN KEY (mat_id) REFERENCES public.material(mat_id) NOT VALID;


--
-- Name: cons_proc cons_proc_con_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_proc
    ADD CONSTRAINT cons_proc_con_id_fkey FOREIGN KEY (con_id) REFERENCES public.consulta(con_id) NOT VALID;


--
-- Name: cons_proc cons_proc_pro_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cons_proc
    ADD CONSTRAINT cons_proc_pro_id_fkey FOREIGN KEY (pro_id) REFERENCES public.procedimento(pro_id) NOT VALID;


--
-- Name: consulta consulta_den_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.consulta
    ADD CONSTRAINT consulta_den_id_fkey FOREIGN KEY (den_id) REFERENCES public.dentista(den_id) NOT VALID;


--
-- Name: consulta consulta_pac_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.consulta
    ADD CONSTRAINT consulta_pac_id_fkey FOREIGN KEY (pac_id) REFERENCES public.paciente(pac_id) NOT VALID;


--
-- PostgreSQL database dump complete
--

