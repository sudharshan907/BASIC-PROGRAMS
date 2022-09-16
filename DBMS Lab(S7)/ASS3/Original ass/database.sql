CREATE TABLE customer (
    cid int,
    cname varchar(30),
    email varchar(30),
    PRIMARY KEY(cid),
    UNIQUE(email)
);


CREATE TABLE payment (
    payid int AUTO_INCREMENT PRIMARY KEY,
    ptype varchar(30),
    pstatus varchar(30),
    pamt int,
    pdate date NOT NULL,
    cid int,
    FOREIGN KEY(cid) REFERENCES customer(cid) ON DELETE CASCADE ON UPDATE CASCADE
);

INSERT INTO `customer`(`cid`, `cname`, `email`) VALUES ('1','ram','ram@');

INSERT INTO `payment`(`payid`, `ptype`, `pstatus`, `pamt`, `pdate`, `cid`) VALUES ('1','a','b','30','2021-09-15','1');

CREATE TABLE theatre (
    thid int,
    name varchar(30),
    location varchar(30),
    PRIMARY KEY(thid)
);

CREATE TABLE tickets (
    tcid int PRIMARY KEY,
    tdate date NOT NULL,
    ttime time NOT NULL,
    thid int,
    FOREIGN KEY(thid) REFERENCES theatre(thid) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE productioncompany (
    prid int PRIMARY KEY,
    pname varchar(30),
       owner varchar(30),
       headq varchar(30)
);

CREATE TABLE movie (
    mid int PRIMARY KEY,
    mname varchar(30),
    prid int,
    FOREIGN KEY(prid) REFERENCES productioncompany(prid) ON DELETE CASCADE ON UPDATE CASCADE,
     thid int,
    FOREIGN KEY(thid) REFERENCES theatre(thid) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE actors(
    aid int,
    aname varchar(30),
    PRIMARY KEY(aid)
);

CREATE TABLE actsin (
    mid int,
    aid int,
    role varchar(30),
    FOREIGN KEY(mid) REFERENCES movie(mid) ON DELETE CASCADE ON UPDATE CASCADE,
     FOREIGN KEY(aid) REFERENCES actors(aid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(mid,aid)
);

CREATE TABLE directors(
    did int,
    dname varchar(30),
    PRIMARY KEY(did)
);


CREATE TABLE seats(
    thid int,
    sno int,
    availability varchar(30),
    seattype varchar(30),
    FOREIGN KEY(thid) REFERENCES theatre(thid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(thid,sno)
);

CREATE TABLE directs(
    mid int,
    did int,
    year year,
    FOREIGN KEY(mid) REFERENCES movie(mid) ON DELETE CASCADE ON UPDATE CASCADE,
     FOREIGN KEY(did) REFERENCES directors(did) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(mid,did)
);

CREATE TABLE c1(
    cid int,
    phno varchar(12),
    FOREIGN KEY(cid) REFERENCES customer(cid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(cid,phno)
);

CREATE TABLE gen(
    mid int,
    genre varchar(30),
    FOREIGN KEY(mid) REFERENCES movie(mid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(mid,genre)
);

CREATE TABLE c2(
    did int,
    phno varchar(12),
    FOREIGN KEY(did) REFERENCES directors(did) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(did,phno)
);

CREATE TABLE c3(
    aid int,
    phno varchar(12),
    FOREIGN KEY(aid) REFERENCES actors(aid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(aid,phno)
);

CREATE TABLE book(
    cid int,
    mid int,
    tcid int,
     FOREIGN KEY(cid) REFERENCES customer(cid) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY(mid) REFERENCES movie(mid) ON DELETE CASCADE ON UPDATE CASCADE,
     FOREIGN KEY(tcid) REFERENCES tickets(tcid) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(cid,mid,tcid)
);

INSERT INTO `customer`(`cid`, `cname`, `email`) VALUES ('2','b','b@');
INSERT INTO `customer`(`cid`, `cname`, `email`) VALUES ('3','c','c@');
INSERT INTO `customer`(`cid`, `cname`, `email`) VALUES ('4','d','d@');
INSERT INTO `customer`(`cid`, `cname`, `email`) VALUES ('5','e','e@');

INSERT INTO `payment`(`payid`, `ptype`, `pstatus`, `pamt`, `pdate`, `cid`) VALUES ('2','a','b','30','2021-09-15','1');
INSERT INTO `payment`(`payid`, `ptype`, `pstatus`, `pamt`, `pdate`, `cid`) VALUES ('3','a','b','30','2021-09-15','2');
INSERT INTO `payment`(`payid`, `ptype`, `pstatus`, `pamt`, `pdate`, `cid`) VALUES ('4','a','b','30','2021-09-15','2');
INSERT INTO `payment`(`payid`, `ptype`, `pstatus`, `pamt`, `pdate`, `cid`) VALUES ('5','a','b','30','2021-09-15','3');

INSERT INTO `c1`(`cid`, `phno`) VALUES ('2','9999999999');
INSERT INTO `c1`(`cid`, `phno`) VALUES ('2','9999999998');
INSERT INTO `c1`(`cid`, `phno`) VALUES ('2','9999999997');
INSERT INTO `c1`(`cid`, `phno`) VALUES ('2','9999999996');
INSERT INTO `c1`(`cid`, `phno`) VALUES ('1','9999999995');
INSERT INTO `c1`(`cid`, `phno`) VALUES ('3','9999999994');

INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('1','a','b');
INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('2','c','d');
INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('3','e','f');
INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('4','g','h');
INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('5','i','j');
INSERT INTO `theatre`(`thid`, `name`, `location`) VALUES ('6','k','l');

INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('1','1','yes','balcony');
INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('1','2','yes','duplex');
INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('1','3','yes','balcony');
INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('4','1','yes','balcony');
INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('4','8','no','top');
INSERT INTO `seats`(`thid`, `sno`, `availability`, `seattype`) VALUES ('3','1','yes','balcony');

INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('1','2022-09-15','06:00:00','1');
INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('2','2022-09-16','01:00:00','1');
INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('3','2022-09-15','02:00:00','1');
INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('4','2022-09-14','07:00:00','2');
INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('5','2022-09-16','06:00:00','3');
INSERT INTO `tickets`(`tcid`, `tdate`, `ttime`, `thid`) VALUES ('6','2022-09-17','06:00:00','4');


INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('1','a','b','c');
INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('2','d','e','f');
INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('3','g','h','i');
INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('4','j','k','l');
INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('5','m','n','o');
INSERT INTO `productioncompany`(`prid`, `pname`, `owner`, `headq`) VALUES ('6','p','q','r');

INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('1','a','1','2');
INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('2','b','1','4');
INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('3','c','2','1');
INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('4','d','4','3');
INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('5','e','1','6');
INSERT INTO `movie`(`mid`, `mname`, `prid`, `thid`) VALUES ('6','f','3','4');


INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('1','1','2');
INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('1','2','2');
INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('3','1','2');
INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('4','1','2');
INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('5','2','1');
INSERT INTO `book`(`cid`, `mid`, `tcid`) VALUES ('2','6','3');

INSERT INTO `gen`(`mid`, `genre`) VALUES ('1','action');
INSERT INTO `gen`(`mid`, `genre`) VALUES ('1','comedy');
INSERT INTO `gen`(`mid`, `genre`) VALUES ('2','action');
INSERT INTO `gen`(`mid`, `genre`) VALUES ('3','comedy');
INSERT INTO `gen`(`mid`, `genre`) VALUES ('4','action');
INSERT INTO `gen`(`mid`, `genre`) VALUES ('4','comedy');

INSERT INTO `directors`(`did`, `dname`) VALUES ('1','a');
INSERT INTO `directors`(`did`, `dname`) VALUES ('2','b');
INSERT INTO `directors`(`did`, `dname`) VALUES ('3','c');
INSERT INTO `directors`(`did`, `dname`) VALUES ('4','d');
INSERT INTO `directors`(`did`, `dname`) VALUES ('5','e');
INSERT INTO `directors`(`did`, `dname`) VALUES ('6','f');


INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('1','2','2019');
INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('2','3','2019');
INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('3','1','2019');
INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('1','3','2019');
INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('4','1','2019');
INSERT INTO `directs`(`mid`, `did`, `year`) VALUES ('5','2','2019');

INSERT INTO `c2`(`did`, `phno`) VALUES ('1','9999999991');
INSERT INTO `c2`(`did`, `phno`) VALUES ('1','9999999993');
INSERT INTO `c2`(`did`, `phno`) VALUES ('1','9999999994');
INSERT INTO `c2`(`did`, `phno`) VALUES ('2','9999999991');
INSERT INTO `c2`(`did`, `phno`) VALUES ('4','9999999991');
INSERT INTO `c2`(`did`, `phno`) VALUES ('5','9999999991');

INSERT INTO `actors`(`aid`, `aname`) VALUES ('1','a');
INSERT INTO `actors`(`aid`, `aname`) VALUES ('2','b');
INSERT INTO `actors`(`aid`, `aname`) VALUES ('3','c');
INSERT INTO `actors`(`aid`, `aname`) VALUES ('4','d');
INSERT INTO `actors`(`aid`, `aname`) VALUES ('5','e');
INSERT INTO `actors`(`aid`, `aname`) VALUES ('6','f');


INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('1','2','hero');
INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('3','2','hero');
INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('1','6','heroine');
INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('4','2','hero');
INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('6','3','heroine');
INSERT INTO `actsin`(`mid`, `aid`, `role`) VALUES ('5','2','hero');


INSERT INTO `c3`(`aid`, `phno`) VALUES ('1','1999999999');
INSERT INTO `c3`(`aid`, `phno`) VALUES ('1','2999999999');
INSERT INTO `c3`(`aid`, `phno`) VALUES ('2','3999999999');
INSERT INTO `c3`(`aid`, `phno`) VALUES ('2','4999999999');
INSERT INTO `c3`(`aid`, `phno`) VALUES ('3','5999999999');
INSERT INTO `c3`(`aid`, `phno`) VALUES ('5','1999999999');

DELETE FROM `c1` WHERE phno='9999999996';

UPDATE `c1` SET `cid`='3',`phno`='9999999996' WHERE phno='9999999997';

SELECT `cid`, `phno` FROM `c1` WHERE phno LIKE '%5';

ALTER TABLE c1 MODIFY phno varchar(20);

SELECT AVG(pamt) FROM payment;













