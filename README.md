
<div>
<p align="center">
	<a href="https://www.42sp.org.br/">
		<img src="./.github/42.png" alt="42" width="500"/> 
	</a>
</p>
</div>
<p align="center">	
   <a href="https://www.linkedin.com/in/luiz-lima-cezario/">
      <img alt="Luiz Cezario" src="https://img.shields.io/badge/-luizCezario-682998?style=flat&logo=Linkedin&logoColor=white" />
   </a>

  <a aria-label="Completed" href="https://www.42sp.org.br/">
    <img src="https://img.shields.io/badge/42.sp-Pipex-682998?logo="></img>
  </a>
  <a href="https://github.com/luizlcezario/Pipex/commits/master">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/luizlcezario/Pipex?color=682998">
  </a> 

  <a href="https://github.com/luizlcezario/Pipex/stargazers">
    <img alt="Stargazers" src="https://img.shields.io/github/stars/luizlcezario/Pipex?color=682998&logo=github">
  </a>
</p>

<div align="center">
  <sub>Push Swap of 42. Make with ❤︎ for
        <a href="https://github.com/luizlcezario">Luiz Cezario</a> 
    </a>
  </sub>
</div>

# Pipex

This is a project to learn about exec and fork in c how they works and other things, in that we recreate the pipe funtion of shell in c.


## Idea

The idea to make the piex work is that you will need to take the command e separete then from the args and after that start a fork for each command one a time and take the result of the exec and pass throght the pipe fds.

## Test

	```bash
	$> make
	$> ./pipex infile "cmd1 args1" "cmd2 aegs2" ... "cmdN argsN" outfile

	```



> So long, and thanks for all the fish!

Give ⭐️ if you like this project, this will help me!
