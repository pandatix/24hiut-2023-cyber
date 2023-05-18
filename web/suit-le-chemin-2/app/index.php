<?php

setcookie(
    'Chemin',
    'UmVuZGV6LXZvdXMgc3VyIC9sYXBldGl0ZWVuaWdtZXF1aWZhaXRwbGFpc2lyLmh0bWw',
    [
        'httponly' => true
    ]
);

if (isset($_GET["page"]) and $_GET["page"]!=="" and isset($_POST["checksum"]) and $_POST["checksum"]!=="") {
	if (hash('sha256', $_GET["page"])===$_POST["checksum"]) {
		$path=preg_replace("/\.\.\//", "", $_GET["page"]);
		$path="/challenge/".$path;
		if (file_exists($path)) {
			include($path);
		}
		else { // Si le fichier demandé n'existe pas
			die('<p style="background-color: red; border: 2px solid black; color: white; width: 500px; margin-top: 50px;margin-left: auto; margin-right: auto; text-align: center">/!\ Adresse IP transmise au créateur du site web pour bannissement /!\ </br> Raison : Tentative d\'exploitation de path traversal. Le fichier "'.$path.'" n\'existe pas.</p>');
		}
	}
	else { // Si les variables page et checksum sont définies mais que sha256(page) est différent de la valeur donnée dans checksum
		die('<p style="background-color: red; border: 2px solid black; color: white; width: 500px; margin-top: 50px;margin-left: auto; margin-right: auto; text-align: center">/!\ Adresse IP transmise au créateur du site web pour bannissement /!\ </br> Raison : Tentative d\'usurpation de la somme de contrôle. Le hash ne correspond pas au fichier demandé !</p>');
	}
}         
else { // Si la variable page et checksum ne sont pas définies -> affichage de la page principale ?>  

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
			  Tu ne crois quand même pas que c'est aussi simple que pour l'étape 1 :)
			  Cependant, je peux d'ores et déjà t'informer que savoir décoder du base64 et hasher des chaines de caractères en SHA256 va t'être utile pour résoudre ce challenge.
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
			<div style="height: 20px; display: flex;">
				<form action="/?page=article1.html" method="POST">
					<a onclick="this.closest('form').submit(); return false;" style="cursor: pointer;">Article 1</a>
					<input type="hidden" name="checksum" value="a33f83816187365c199092ce09f42a0f2d78698a2054e981c52bd1d026804119">
				</form>
				<form action="/?page=article2.html" method="POST">
					<a onclick="this.closest('form').submit(); return false;" style="cursor: pointer;">Article 2</a>
					<input type="hidden" name="checksum" value="724e65e10da7c7490cb63f5ed238a6f9d7382a6becf941a8c731422b457a794c">
				</form>
				<a href="https://superlogout.com/">Article secret</a>
			</div>
				<form action="/?page=login.html" method="POST">
					<a onclick="this.closest('form').submit(); return false;" style="cursor: pointer;">Se connecter</a>
					<input type="hidden" name="checksum" value="f7df8ca1f6a5b4e55cc08d43d079af1235a1a87cf8799fe7813f42440378ef4a">
				</form>
		</header>
		<p class="warning" style="margin-left: auto; margin-right: auto; text-align: center">Ce blog est encore en cours de construction</p>
		<main>
			<div class="square-container">
				<div class="square">
					<form action="/?page=article1.html" method="POST">
						<img onclick="this.closest('form').submit(); return false;" style="cursor: pointer;" src="article1.jpg"/>
						<div style="background-color: white;">
							<h3>Article 1</h3>
							</br>
							<p style="text-align:center">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
						</div>
						<input type="hidden" name="checksum" value="a33f83816187365c199092ce09f42a0f2d78698a2054e981c52bd1d026804119">
					</form>
				</div>
				<div class="square">
					<form action="/?page=article2.html" method="POST">
						<img onclick="this.closest('form').submit(); return false;" style="cursor: pointer;" src="article2.jpg"/>
						<div style="background-color: white;">
							<h3>Article 2</h3>
							</br>
							<p style="text-align:center">Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt.</p>
						</div>
						<input type="hidden" name="checksum" value="724e65e10da7c7490cb63f5ed238a6f9d7382a6becf941a8c731422b457a794c">
					</form>
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