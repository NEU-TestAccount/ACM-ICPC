"set cin aw ai is ts=4 sw=4 tm=50 nu noeb bg=dark ru cul
"sy on   |   im jk <esc>   |   im kj <esc>   |   no ; :
"<Normal Mode> :r $VIMRUNTIME/vimrc_example.vim
set nohls showcmd showmatch incsearch ru nu si cursorline showmode sw=4 ts=4 noet
func Debug()
	:w
	:!g++ % -DDEBUG -std=c++11 -o %<.exe
endfunc
map <F5> :call Debug()<CR>
