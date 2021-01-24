// /***********************
//   Load Components!

//   Express      - A Node.js Framework
//   Body-Parser  - A tool to help use parse the data in a post request
//   Pg-Promise   - A database tool to help use connect to our PostgreSQL database
// ***********************/
var express = require('express'); //Ensure our express framework has been added
var app = express();
var bodyParser = require('body-parser'); //Ensure our body-parser tool has been added
var session = require('express-session');
app.use(session({
	secret: 'secret',
	resave: true,
	saveUninitialized: true
}));
app.use(bodyParser.json());              // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })); // support encoded bodies


//Create Database Connection
var pgp = require('pg-promise')();

// /**********************
//   Database Connection information
// **********************/

let dbConfig = {
    host: 'ec2-54-84-98-18.compute-1.amazonaws.com',
    port: 5432,
    database: 'd54dd8qjq3nktf',
    user: 'rzwgdueiiqelyf',
    password: 'a6c3efbd67d5b34c2a182adb4faf6e418143f7e3eb6d69899a3d1d175be30c8a',
    ssl: true
};

const isProduction = process.env.NODE_ENV === 'production';
dbConfig = isProduction ? process.env.DATABASE_URL : dbConfig;
let db = pgp(dbConfig);

// set the view engine to ejs
app.set('view engine', 'ejs');
app.use(express.static(__dirname + '/'));//This line is necessary for us to use relative paths and access our resources directory


// login page
app.get('/', function(req, res) {
	res.render('pages/login',{
		local_css:"signin.css",
		my_title:"Login Page"
	});
});

app.post('/auth', function(req, res) {
	var username = req.body.Username;
    var password = req.body.Password;
	if (username && password) {
        var query = 'SELECT * FROM login WHERE username = $1 AND password = $2';
        const values = [username, password];
        db.query(query, values)
        .then(data => {
            if (data.length > 0) {
				req.session.loggedin = true;
				req.session.username = username;
                res.render('pages/home',{
                    my_title: "Home Page",
                })
			} else {
                res.send('Incorrect Username and/or Password!');
			}			
			res.end();
		});
	} else {
		res.send('Please enter Username and Password!');
		res.end();
	}
});

// registration page
app.get('/register', function(req, res) {
	res.render('pages/register',{
		my_title:"Registration Page"
	});
});

app.post('/addUser', function(req, res) {
	var username = req.body.Username;
    var password = req.body.Password;
	var insert_statement = "INSERT INTO login(Username, Password) VALUES('" + username + "','" +
							password +"');";
    db.task('get-everything', task => {
        return task.batch([
            task.any(insert_statement)
        ]);
        }).then(info => {
            res.redirect('/')
        })
        .catch(error => {
            res.send('Failed to register! Username already exists.');
        });
});

// home page
app.get('/home', function(req, res) {
	if (req.session.loggedin) {
		res.render('pages/home',{
            my_title: "Home Page",
            data: '',
            color: '',
            color_msg: ''
        })
	} else {
		res.send('Please login to view this page!');
	}
	res.end();
});


// Assets Page
app.get('/assets', function(req, res) {
		res.render('pages/assets',{
            my_title: "Assets",
        })
	res.end();
});


// High Scores Page
app.get('/high_scores', function(req, res) {
    if (req.session.loggedin) {
    var get_scores = 'select * from high_score order by score desc limit 100;';

    db.task('get-everything', task => {
        return task.batch([
            task.any(get_scores)
        ]);
    })
    .then(data => {
    	res.render('pages/high_scores',{
                my_title: "High Scores",
                scores: data[0]
			})
    })
    .catch(error => {
        res.send('Failed to load High Scores. Please try again!');
    })
    }else {
		res.send('Please login to view this page!')
    }
});

// // app.listen(3000);
const PORT = process.env.PORT || 8080;

const server = app.listen(PORT, () => {
	console.log(`Express running → PORT ${server.address().port}`);
});
