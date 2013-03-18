if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <F8> ^i/*$a*/ 
imap <F2> :sh 
imap <C-Tab> :tabnexti
imap <C-S-Tab> :tabpreviousi
inoremap <silent> <F11> :VSTreeExplore .i
inoremap <silent> <F12> :TlistTogglei
inoremap <F5> :wi
nnoremap  :tabnew:VSTreeExplore .
nnoremap <silent> w :CCTreeWindowToggle
nnoremap <silent> y :CCTreeWindowSaveCopy
map + +
map - -
map < <
map > >
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
map <F2> :sh 
map <F4> :%s/^[0-9]*//g:%s/.$//g:%s/’’/"/g:%s/‘‘/"/g
nmap <C-Tab> :tabnext
nmap <C-S-Tab> :tabprevious
nnoremap <silent> <F11> :VSTreeExplore .
nnoremap <silent> <F12> :TlistToggle
map <F5> :w
map <F3> ggvG=
inoremap  :tabnew:VSTreeExplorei
inoremap <expr>  omni#cpp#maycomplete#Complete()
inoremap "" ""i
inoremap ""; "";hi
inoremap '' ''i
inoremap ''; '';hi
inoremap ((; ();hi
inoremap (( ()i
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap <expr> > omni#cpp#maycomplete#Arrow()
inoremap [[; []hi
inoremap [[ []i
inoremap {{; {};ki<Right>
inoremap {{ {}ki<Right>
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set backspace=indent,eol,start
set completeopt=menuone,longest
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set listchars=tab:>\ 
set mouse=a
set omnifunc=omni#cpp#complete#Main
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set shiftwidth=4
set showcmd
set softtabstop=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/cpp/tags
set nowritebackup
" vim: set ft=vim :
