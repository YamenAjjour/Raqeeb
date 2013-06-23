--
-- PostgreSQL database dump
--

-- Dumped from database version 9.0.3
-- Dumped by pg_dump version 9.0.3
-- Started on 2011-10-08 09:51:20

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = off;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET escape_string_warning = off;

--
-- TOC entry 324 (class 2612 OID 11574)
-- Name: plpgsql; Type: PROCEDURAL LANGUAGE; Schema: -; Owner: postgres
--

CREATE OR REPLACE PROCEDURAL LANGUAGE plpgsql;


ALTER PROCEDURAL LANGUAGE plpgsql OWNER TO postgres;

SET search_path = public, pg_catalog;

--
-- TOC entry 19 (class 1255 OID 16480)
-- Dependencies: 324 6
-- Name: addemployee(integer, character varying, character varying, character varying, character varying, character varying, character varying, double precision); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION addemployee(integer, character varying, character varying, character varying, character varying, character varying, character varying, double precision) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$
declare 
employeeid alias for $1;
fname alias for $2;
lname alias for $3;
empemail alias for $4;
empphone alias for $5;
aemail alias for $6;
empmobile alias for $7;
hprice alias for $8;
num integer;
name character varying(100);
BEGIN
select count(*) into num from emp where empid=employeeid;
if( num > 0) then
return false;
end if ;
select count(*) into num from emp where firstname=fname;
if(num > 0 ) then 
return false;
end if ;
insert into emp(empid,firstname,lastname,email,phone,anotheremail,mobile,hourprice) values(employeeid,fname,lname,empemail,empphone,aemail,empmobile,hprice);
return true;
END;
$_$;


ALTER FUNCTION public.addemployee(integer, character varying, character varying, character varying, character varying, character varying, character varying, double precision) OWNER TO postgres;

--
-- TOC entry 20 (class 1255 OID 16481)
-- Dependencies: 6 324
-- Name: addleave(date, date, integer, integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION addleave(date, date, integer, integer) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$
DECLARE 
ldate ALIAS for $1;
rdate ALIAS for $2;
ispaid ALIAS for $3;
employid ALIAS for $4;
leaveid integer;
leave record;
BEGIN 
select * from emp where empid=id;
if not found then 
	return 'false';
else
	insert into leave(leavedate,reqdate,paid) values(ldate,radate,ispaid);
	select into leaveid max(empid) from emp ;
	insert into emp_leave(empid,leaveid)values(employid,leaveid);
	return 'true';
	
END IF;
END;
$_$;


ALTER FUNCTION public.addleave(date, date, integer, integer) OWNER TO postgres;

--
-- TOC entry 21 (class 1255 OID 16483)
-- Dependencies: 324 6
-- Name: addleavetoall(date, date, integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION addleavetoall(date, date, integer) RETURNS boolean
    LANGUAGE plpgsql
    AS $_$
DECLARE 
ldate ALIAS for $1;
rdate ALIAS for $2;
ispaid ALIAS for $3;
leaveid integer;
employe record;
BEGIN 
perform * from emp  ;
if not found then 
	return false;
else
	insert into leave(leavedate,reqdate,paid) values(ldate,radate,ispaid);
	for employe in select * from emp 
    LOOP   
	    insert into emp_leave(employe.empid,leaveid)values(employid,leaveid);
    End LOOP;
	return 'true';
END IF;
END;
$_$;


ALTER FUNCTION public.addleavetoall(date, date, integer) OWNER TO postgres;

--
-- TOC entry 15 (class 1255 OID 16451)
-- Dependencies: 6 324
-- Name: getemp(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION getemp() RETURNS boolean
    LANGUAGE plpgsql
    AS $$
begin
select * from emp;
end;$$;


ALTER FUNCTION public.getemp() OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 1516 (class 1259 OID 16406)
-- Dependencies: 6
-- Name: bounceDeduction; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE "bounceDeduction" (
    "bounce-id" integer NOT NULL,
    amount double precision NOT NULL,
    email character varying(100) NOT NULL,
    phone character varying(100),
    mobile character varying(100) NOT NULL,
    "anotherEmail" character varying(100),
    "empId" integer NOT NULL
);


ALTER TABLE public."bounceDeduction" OWNER TO postgres;

--
-- TOC entry 1517 (class 1259 OID 16409)
-- Dependencies: 6 1516
-- Name: bounceDeduction_bounce-id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE "bounceDeduction_bounce-id_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."bounceDeduction_bounce-id_seq" OWNER TO postgres;

--
-- TOC entry 1831 (class 0 OID 0)
-- Dependencies: 1517
-- Name: bounceDeduction_bounce-id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE "bounceDeduction_bounce-id_seq" OWNED BY "bounceDeduction"."bounce-id";


--
-- TOC entry 1832 (class 0 OID 0)
-- Dependencies: 1517
-- Name: bounceDeduction_bounce-id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('"bounceDeduction_bounce-id_seq"', 1, false);


--
-- TOC entry 1518 (class 1259 OID 16411)
-- Dependencies: 6
-- Name: emp; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE emp (
    empid integer NOT NULL,
    firstname character varying(100) NOT NULL,
    lastname character varying(100) NOT NULL,
    email character varying(100) NOT NULL,
    phone character varying(100) NOT NULL,
    anotheremail character varying(100) NOT NULL,
    mobile character varying(64),
    hourprice double precision
);


ALTER TABLE public.emp OWNER TO postgres;

--
-- TOC entry 1519 (class 1259 OID 16417)
-- Dependencies: 1518 6
-- Name: emp_empId_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE "emp_empId_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."emp_empId_seq" OWNER TO postgres;

--
-- TOC entry 1833 (class 0 OID 0)
-- Dependencies: 1519
-- Name: emp_empId_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE "emp_empId_seq" OWNED BY emp.empid;


--
-- TOC entry 1834 (class 0 OID 0)
-- Dependencies: 1519
-- Name: emp_empId_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('"emp_empId_seq"', 1, false);


--
-- TOC entry 1524 (class 1259 OID 16460)
-- Dependencies: 6
-- Name: emp_leave; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE emp_leave (
    empid integer NOT NULL,
    leaveid integer NOT NULL
);


ALTER TABLE public.emp_leave OWNER TO postgres;

--
-- TOC entry 1523 (class 1259 OID 16454)
-- Dependencies: 6
-- Name: leave; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE leave (
    id integer NOT NULL,
    leavedate date NOT NULL,
    reqdate date NOT NULL,
    paid integer NOT NULL
);


ALTER TABLE public.leave OWNER TO postgres;

--
-- TOC entry 1522 (class 1259 OID 16452)
-- Dependencies: 6 1523
-- Name: leave_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE leave_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.leave_id_seq OWNER TO postgres;

--
-- TOC entry 1835 (class 0 OID 0)
-- Dependencies: 1522
-- Name: leave_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE leave_id_seq OWNED BY leave.id;


--
-- TOC entry 1836 (class 0 OID 0)
-- Dependencies: 1522
-- Name: leave_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('leave_id_seq', 1, false);


--
-- TOC entry 1520 (class 1259 OID 16419)
-- Dependencies: 1804 6
-- Name: salaryComp; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE "salaryComp" (
    "compId" integer NOT NULL,
    month integer NOT NULL,
    "numOfHour" integer NOT NULL,
    "hourPrice" double precision NOT NULL,
    empid integer NOT NULL,
    "isRemote" integer DEFAULT 0 NOT NULL
);


ALTER TABLE public."salaryComp" OWNER TO postgres;

--
-- TOC entry 1521 (class 1259 OID 16423)
-- Dependencies: 1520 6
-- Name: salaryComp_compId_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE "salaryComp_compId_seq"
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."salaryComp_compId_seq" OWNER TO postgres;

--
-- TOC entry 1837 (class 0 OID 0)
-- Dependencies: 1521
-- Name: salaryComp_compId_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE "salaryComp_compId_seq" OWNED BY "salaryComp"."compId";


--
-- TOC entry 1838 (class 0 OID 0)
-- Dependencies: 1521
-- Name: salaryComp_compId_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('"salaryComp_compId_seq"', 1, false);


--
-- TOC entry 1802 (class 2604 OID 16425)
-- Dependencies: 1517 1516
-- Name: bounce-id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE "bounceDeduction" ALTER COLUMN "bounce-id" SET DEFAULT nextval('"bounceDeduction_bounce-id_seq"'::regclass);


--
-- TOC entry 1803 (class 2604 OID 16426)
-- Dependencies: 1519 1518
-- Name: empid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE emp ALTER COLUMN empid SET DEFAULT nextval('"emp_empId_seq"'::regclass);


--
-- TOC entry 1806 (class 2604 OID 16457)
-- Dependencies: 1523 1522 1523
-- Name: id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE leave ALTER COLUMN id SET DEFAULT nextval('leave_id_seq'::regclass);


--
-- TOC entry 1805 (class 2604 OID 16427)
-- Dependencies: 1521 1520
-- Name: compId; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE "salaryComp" ALTER COLUMN "compId" SET DEFAULT nextval('"salaryComp_compId_seq"'::regclass);


--
-- TOC entry 1821 (class 0 OID 16406)
-- Dependencies: 1516
-- Data for Name: bounceDeduction; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY "bounceDeduction" ("bounce-id", amount, email, phone, mobile, "anotherEmail", "empId") FROM stdin;
\.


--
-- TOC entry 1822 (class 0 OID 16411)
-- Dependencies: 1518
-- Data for Name: emp; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY emp (empid, firstname, lastname, email, phone, anotheremail, mobile, hourprice) FROM stdin;
21321	12	123	123	21321	21321	3212	12321
1	yamen	asfafa	asdfsadf	asdfsadf	adsfsaf	afasfsadf	312310
2	yame2n	asfafa	asdfsadf	asdfsadf	adsfsaf	afasfsadf	312310
213213	213	21321321	2321321	213123	213213	213213	21321312
\.


--
-- TOC entry 1825 (class 0 OID 16460)
-- Dependencies: 1524
-- Data for Name: emp_leave; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY emp_leave (empid, leaveid) FROM stdin;
\.


--
-- TOC entry 1824 (class 0 OID 16454)
-- Dependencies: 1523
-- Data for Name: leave; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY leave (id, leavedate, reqdate, paid) FROM stdin;
\.


--
-- TOC entry 1823 (class 0 OID 16419)
-- Dependencies: 1520
-- Data for Name: salaryComp; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY "salaryComp" ("compId", month, "numOfHour", "hourPrice", empid, "isRemote") FROM stdin;
\.


--
-- TOC entry 1808 (class 2606 OID 16429)
-- Dependencies: 1516 1516
-- Name: bounceDeduction_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "bounceDeduction"
    ADD CONSTRAINT "bounceDeduction_pkey" PRIMARY KEY ("bounce-id");


--
-- TOC entry 1816 (class 2606 OID 16464)
-- Dependencies: 1524 1524 1524
-- Name: emp_leave_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY emp_leave
    ADD CONSTRAINT emp_leave_pkey PRIMARY KEY (empid, leaveid);


--
-- TOC entry 1810 (class 2606 OID 16431)
-- Dependencies: 1518 1518
-- Name: emp_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY emp
    ADD CONSTRAINT emp_pkey PRIMARY KEY (empid);


--
-- TOC entry 1814 (class 2606 OID 16459)
-- Dependencies: 1523 1523
-- Name: leave_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY leave
    ADD CONSTRAINT leave_pkey PRIMARY KEY (id);


--
-- TOC entry 1812 (class 2606 OID 16433)
-- Dependencies: 1520 1520
-- Name: salaryComp_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "salaryComp"
    ADD CONSTRAINT "salaryComp_pkey" PRIMARY KEY ("compId");


--
-- TOC entry 1819 (class 2606 OID 16465)
-- Dependencies: 1809 1524 1518
-- Name: fk_emp; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY emp_leave
    ADD CONSTRAINT fk_emp FOREIGN KEY (empid) REFERENCES emp(empid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 1818 (class 2606 OID 16434)
-- Dependencies: 1809 1518 1520
-- Name: fk_empId; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY "salaryComp"
    ADD CONSTRAINT "fk_empId" FOREIGN KEY (empid) REFERENCES emp(empid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 1817 (class 2606 OID 16439)
-- Dependencies: 1518 1516 1809
-- Name: fk_emp_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY "bounceDeduction"
    ADD CONSTRAINT fk_emp_id FOREIGN KEY ("empId") REFERENCES emp(empid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 1820 (class 2606 OID 16470)
-- Dependencies: 1523 1524 1813
-- Name: fk_leave; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY emp_leave
    ADD CONSTRAINT fk_leave FOREIGN KEY (leaveid) REFERENCES leave(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 1830 (class 0 OID 0)
-- Dependencies: 6
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2011-10-08 09:51:21

--
-- PostgreSQL database dump complete
--

