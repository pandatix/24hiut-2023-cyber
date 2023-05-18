<?php
if (isset($_GET["page"]) and $_GET["page"]!=="") {
	include($_GET["page"]);
}
else { ?>  
<!DOCTYPE html>
<html>
	<head>
		<title>Mon Super Site Web</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<style>
			  /* Style général de la page */
			  * {
				box-sizing: border-box;
				margin: 0;
				padding: 0;
			  }
			  body {
				font-family: Arial, sans-serif;
			  }
			  
			  /* Style de la partie en haut */
			  #header {
				background-color: #333;
				color: #fff;
				display: flex;
				justify-content: space-between;
				padding: 10px 20px;
			  }
			  #header a {
				color: #fff;
				text-decoration: none;
			  }
			  
			  /* Style des carrés */
			  .square-container {
				display: flex;
				justify-content: space-between;
				padding: 20px;
			  }
			  .square {
				background-color: #f1f1f1;
				width: 33%;
				margin-bottom: 20px;
				margin-top: 50px;
				height: 33%;
				background: lightgray;
			  }
			  
			  h3 {
				text-align:center
			  }
			  
			  img {
				width: 100%
			  }
			
			  a {
				margin-top: auto;
				margin-bottom: auto;
				margin-right: 20px;
			  }	
			
			  /*
			  /chemindelavictoire.html
			  */
			
			  .warning {
				background-color: #FDF7DF;
				border: 1px solid #FEEC6F;
				color: #C9971C;
				width: 500px;
				margin-left: 20px;
				margin-top: 50px;
			  }
		</style>
	</head>
	<body>
		<header id="header">
			<a href="/">Home</a>
			<div style="height: 20px;">
				<a href="/?page=article1.html">Article 1</a>
				<a href="/?page=article2.html">Article 2</a>
				<a href="https://superlogout.com/">Article secret</a>
			</div>
			<a href="/?page=login.html">Se Connecter</a>
		</header>
		<p class="warning" style="margin-left: auto; margin-right: auto; text-align: center">Ce blog est encore en cours de construction</p>
		<main>
			<div class="square-container">
				<div class="square">
					<a href="?page=article1.html">
						<img src="article1.jpg"/>
					</a>
					<div style="background-color: white;">
						<h3>Article 1</h3>
						</br>
						<p style="text-align:center">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
					</div>
				</div>
				<div class="square">
					<a href="?page=article2.html">
						<img src="article2.jpg"/>
					</a>
					<div style="background-color: white;">
						<h3>Article 2</h3>
						</br>
						<p style="text-align:center">Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt.</p>
					</div>
				</div>
				<div class="square">
					<a href="https://superlogout.com/">
						<img src="articlesecret.jpg"/>
					</a>
					<div style="background-color: white;">
						<h3>Article Secret</h3>
						</br>
						<p style="text-align:center">Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?</p>
					</div>
				</div>
			</div>
		</main>
	</body>
</html>
<?php
}
